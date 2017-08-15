import sys
from PyQt5.QtWidgets import (
        QWidget,
        QMessageBox,
        QApplication,
        QAction,
        QMainWindow,
        qApp,
        QDesktopWidget
)

class Experiment(QMainWindow):

        def __init__(self):

                super().__init__()

                self.initUI()

        def initUI(self):

                self.resize(800, 450)
                self.center()

                self.initMenu()

                self.statusBar().showMessage("Locked and Loaded")

                self.setWindowTitle('Evil Experiment 01')

                self.show()

        def initMenu(self):
                exitAct = QAction("Exit", self)
                exitAct.setShortcut('Ctrl+Q')
                exitAct.setStatusTip('Exit application')
                exitAct.triggered.connect(qApp.quit)

                menuBar = self.menuBar()
                fileMenu = menuBar.addMenu("File")
                fileMenu.addAction(exitAct)

        def center(self):
                qr = self.frameGeometry() #rectangle that describes the geometry of the window
                cp = QDesktopWidget().availableGeometry().center() #center point of the screen
                qr.moveCenter(cp) #move the variable qr to the center of the screen
                #move the top left corner of the window to the top left corner of qr
                self.move(qr.topLeft())





        #implements and event handler for the window's close button
        """
        def closeEvent(self, event):

                reply = QMessageBox.question(self, 'Message', "Are you sure you want to quit?",
                                             QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
                if reply == QMessageBox.Yes:
                        event.accept()
                else:
                        event.ignore()
        """

if __name__ == '__main__':

        app = QApplication(sys.argv)
        ex = Experiment()
        sys.exit(app.exec_())
