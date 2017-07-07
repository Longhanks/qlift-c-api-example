#ifdef __cplusplus
#error No c++
#endif

#include <stdio.h>

#include "qlift-c-api.h"

void slot(int checked) {
    printf("You clicked, button is checked: %i\n", checked);
}

int main(int argc, char *argv[]) {
    void *application = QApplication_new(&argc, argv);
    void *mainWindow = QMainWindow_new(NULL, 0);
    void *pushButton = QPushButton_new(NULL, "Push me!", mainWindow);
    QAbstractButton_clicked_connect(pushButton, pushButton, &slot);
    QMainWindow_setCentralWidget(mainWindow, pushButton);
    QWidget_show(mainWindow);
    int result = QCoreApplication_exec(application);
    return result;
}
