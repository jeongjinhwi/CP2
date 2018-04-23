#pragma once
#include "AppIO.h"
#include "Ban.h"
#include "Common.h"
typedef struct AppController AppController;

AppController* AppController_new(void);
void AppController_delete(AppController* _this);
void AppController_run(AppController* _this);
Boolean AppController_inputAndStoreStudents(AppController* _this);
void AppController_showStatistics(AppController* _this);
void AppController_showStudentsSortedByScore(AppController* _this);