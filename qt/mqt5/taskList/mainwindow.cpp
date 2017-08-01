#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QInputDialog>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    mTasks()
{
    ui->setupUi(this);

    connect(ui->addTaskButton, &QPushButton::clicked,
            this, &MainWindow::addTask);

    updateStatus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTask()
{
    bool ok;
    QString name = QInputDialog::getText(this,
                                         tr("Add Task"),
                                         tr("Task name"),
                                         QLineEdit::Normal,
                                         tr("Untitled task"), &ok);
    if (ok && !name.isEmpty()) {
        qDebug() << "Adding new task";
        Task* task = new Task(name);
        connect(task, &Task::removed, this, &MainWindow::remove);
        connect(task, &Task::statusChanged, this, &MainWindow::taskStatusChanged);
        mTasks.append(task);
        ui->tasksLayout->addWidget(task);
        updateStatus();

    }
}

void MainWindow::remove(Task* task)
{
    QMessageBox::StandardButton confirm;
    confirm = QMessageBox::question(this, tr("Confirmation"),
                                    tr("Are you sure you want to delete this task?"),
                                    QMessageBox::Yes|QMessageBox::No);
    if (confirm == QMessageBox::Yes)
    {
    mTasks.removeOne(task);
    ui->tasksLayout->removeWidget(task);
    task->setParent(0);
    delete task;
    updateStatus();
    }
}

void MainWindow::taskStatusChanged(Task* /*task*/)
{
    updateStatus();
}

void MainWindow::updateStatus()
{
    int completedCount = 0;
    for (auto t : mTasks) {
        if (t->isCompleted()) {
            completedCount++;
        }
    }
    int taskCount = mTasks.size() - completedCount;

    ui->statusLabel->setText(QString("Status %1 todo / %2 completed")
                           .arg(taskCount).arg(completedCount));
}
