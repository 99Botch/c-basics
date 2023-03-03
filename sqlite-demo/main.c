
#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int getUsers(void *data, int argc, char **argv, char **azColName);

int main(int argc, char *argv[]) {
  system("clear");

  sqlite3 *db_ptr;
  char *errMesg = 0;

  int ret = 0;
  const char *data = "User";

  ret = sqlite3_open("demo.db", &db_ptr);

  if (ret != SQLITE_OK) {
    printf("Database opening error\n");
  }

  char *sql_stmt = "CREATE TABLE IF NOT EXISTS Users(id INTEGER PRIMARY KEY, "
                   "name TEXT, salary INT);";

  ret = sqlite3_exec(db_ptr, sql_stmt, 0, 0, &errMesg);

  if (ret != SQLITE_OK) {

    printf("Error in SQL statement: %s\n", errMesg);

    sqlite3_free(errMesg);
    sqlite3_close(db_ptr);

    return 1;
  }

  printf("Data inserted successfully\n\n");

  printf(">>> SELECT AN ACTION BELOW <<<\n\n");

  printf("1. Add an item to db\n");
  printf("2. Get items from db\n");
  printf("3. Get an item from db\n");
  printf("4. Update item\n");
  printf("5. Remove item\n");
  printf("6. Quit program\n\n");

  int isQuitting = 0;
  char selec[25];

  while (!isQuitting) {

    printf("Select: ");
    fgets(selec, 25, stdin);
    printf("\n");
    selec[strcspn(selec, "\n")] = '\0';
    char *ptr;
    long selection;
    selection = strtol(selec, &ptr, 10);

    if (selection == 1) {

      char name[50], salary[10];
      printf("Give user's name: ");
      fgets(name, 50, stdin);
      name[strcspn(name, "\n")] = '\0';

      printf("Give user's salary: ");
      fgets(salary, 10, stdin);
      salary[strcspn(salary, "\n")] = '\0';
      long slr;
      slr = strtol(salary, &ptr, 10);

      char *query = sqlite3_mprintf(
          "INSERT INTO Users ('name', 'salary') VALUES ('%q', %d);", name, slr);
      ret = sqlite3_exec(db_ptr, query, NULL, NULL, &errMesg);

      if (ret != SQLITE_OK) {
        printf("Error in SQL statement: %s\n", errMesg);
      } else {
        printf("DB updated successfully\n\n");
      }

      sqlite3_free(errMesg);
      sqlite3_free(query);
    } else if (selection == 2) {

      char *query = "SELECT * from Users";
      ret = sqlite3_exec(db_ptr, query, getUsers, (void *)data, &errMesg);

      if (ret != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMesg);
        sqlite3_free(errMesg);
      }

    } else if (selection == 3) {

      char name[25];

      printf("Who are you looking for? ");
      fgets(name, 25, stdin);
      name[strcspn(name, "\n")] = '\0';

      char *query =
          sqlite3_mprintf("SELECT * FROM Users WHERE name = '%q';", name);
      ret = sqlite3_exec(db_ptr, query, getUsers, (void *)data, &errMesg);

      if (ret != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMesg);
        sqlite3_free(errMesg);
      }

    } else if (selection == 4) {

      char name[25], new_name[50], salary[10];

      printf("Who are you updating? ");
      fgets(name, 25, stdin);
      name[strcspn(name, "\n")] = '\0';

      printf("Give user's new name: ");
      fgets(new_name, 50, stdin);
      new_name[strcspn(new_name, "\n")] = '\0';

      printf("Give user's salary: ");
      fgets(salary, 10, stdin);
      salary[strcspn(salary, "\n")] = '\0';
      long slr;
      slr = strtol(salary, &ptr, 10);


      char *query = sqlite3_mprintf(
          "UPDATE Users SET name= '%q', salary = %d WHERE name = '%q';",
          new_name, slr, name);
      ret = sqlite3_exec(db_ptr, query, getUsers, (void *)data, &errMesg);

      if (ret != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMesg);
        sqlite3_free(errMesg);
      } else {
        printf("DB updated sucessfully\n\n");
      }

    } else if (selection == 5) {

      char name[25];

      printf("Give user's name to delete: ");
      fgets(name, 25, stdin);
      name[strcspn(name, "\n")] = '\0';

      char *query =
          sqlite3_mprintf("DELETE FROM Users WHERE name = '%q';", name);
      ret = sqlite3_exec(db_ptr, query, NULL, NULL, &errMesg);

      if (ret != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMesg);
        sqlite3_free(errMesg);
      } else {
        printf("Deletion succesfull\n\n");
      }

      free(query);
      sqlite3_free(errMesg);

    } else if (selection == 6) {
      isQuitting = 1;
      printf("Quitting..\n");
    } else {
      printf("Wrong input, select an action between 1 & 6\n\n");
    }
  }

  sqlite3_close(db_ptr);
  return 0;
}

static int getUsers(void *data, int argc, char **argv, char **azColName) {
  int i;
  fprintf(stderr, "%s: ", (const char *)data);

  for (i = 0; i < argc; i++) {
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }

  printf("\n");
  return 0;
}