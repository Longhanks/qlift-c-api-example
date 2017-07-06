#ifdef __cplusplus
#error No c++
#endif

#include "qlift-c-api.h"

int main(int argc, char *argv[]) {
    void *app = QApplication_ctor(&argc, argv);
    void *mainWindow = QMainWindow_ctor_parent_default_flags_default();
    void *label = QLabel_ctor_text_arg1_parent_arg2_flags_default("Hello, world!", mainWindow);
    QLabel_setAlignment(label, 132);
    QMainWindow_setCentralWidget(mainWindow, label);
    QMainWindow_show(mainWindow);
    int result = QApplication_exec(app);
    return result;
}
