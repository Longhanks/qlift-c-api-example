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
    void *widget = QWidget_new(NULL, 0);
    void *layout = QVBoxLayout_new(widget);
    void *label = QLabel_new("Hello, world!", NULL, 0);
    QLabel_setAlignment(label, 132);
    void *pushButton = QPushButton_new(NULL, "Push me!", mainWindow);
    QAbstractButton_clicked_connect(pushButton, pushButton, &slot);
    void *spacer1 = QSpacerItem_new(20, 40, 1, 7);
    void *spacer2 = QSpacerItem_new(20, 40, 1, 7);
    QBoxLayout_addWidget(layout, label, 0, 0);
    QBoxLayout_addItem(layout, spacer1);
    QBoxLayout_addWidget(layout, pushButton, 0, 0);
    QBoxLayout_addItem(layout, spacer2);
    QMainWindow_setCentralWidget(mainWindow, widget);
    void *menubar = QMenuBar_new(NULL);
    void *menu = QMenu_new("File", menubar);
    void *action = QAction_new(NULL, "Exit", menu);
    QWidget_addAction(menu, action);
    QWidget_addAction(menubar, QMenu_menuAction(menu));
    QMainWindow_setMenuBar(mainWindow, menubar);
    QWidget_show(mainWindow);
    int result = QCoreApplication_exec(application);
    return result;
}
