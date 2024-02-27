#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QInputDialog>

class MyWindow : public QWidget {
public:
    MyWindow(QWidget *parent = nullptr) : QWidget(parent) {
        setFixedSize(400, 300);

        startButton = new QPushButton("开始程序", this);
        startButton->setGeometry(50, 50, 100, 30);
        connect(startButton, &QPushButton::clicked, this, &MyWindow::startProgram);

        stopButton = new QPushButton("结束程序", this);
        stopButton->setGeometry(50, 100, 100, 30);
        connect(stopButton, &QPushButton::clicked, this, &MyWindow::stopProgram);

        setCPUUsageButton = new QPushButton("设置CPU使用率", this);
        setCPUUsageButton->setGeometry(50, 150, 150, 30);
        connect(setCPUUsageButton, &QPushButton::clicked, this, &MyWindow::setCPUUsage);
    }

private slots:
    void startProgram() {
        QMessageBox::information(this, "提示", "程序已经开始运行");
    }

    void stopProgram() {
        QMessageBox::information(this, "提示", "程序已经结束运行");
    }

    void setCPUUsage() {
        bool ok;
        float cpuUsage = QInputDialog::getDouble(this, "设置CPU使用率", "请输入希望设置的CPU使用率 (0-100):", 0, 0, 100, 1, &ok);
        if (ok) {
            if (cpuUsage < 0 || cpuUsage > 100) {
                QMessageBox::warning(this, "错误", "CPU使用率必须在0到100之间");
            } else {
                // 这里可以添加设置CPU使用率的代码
                QMessageBox::information(this, "提示", QString("CPU使用率已设置为 %1%").arg(cpuUsage));
            }
        }
    }

private:
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *setCPUUsageButton;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MyWindow window;
    window.setWindowTitle("CPU控制程序");
    window.show();

    return app.exec();
}
