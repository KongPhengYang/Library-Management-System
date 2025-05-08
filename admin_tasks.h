#ifndef ADMIN_TASKS_H
#define ADMIN_TASKS_H

#include "Admin.h"
#include "User.h"
#include "Book.h"
Admin* loginAdmin();

void adminTasks(Admin* a);

Book* newBook();
void manageInventory(Admin* a);
void manageUsers(Admin* a);
void printStats();
void borrowAndReturn(Admin* a);

#endif
