import sys
from PyQt5.QtWidgets import QWidget, QPushButton, QApplication
from PyQt5.QtCore import QCoreApplication

class Example(QWidget):
        
        def __init__(self):
                super().__init__()
                
                self.initUI()

        def initUI(self):
                
                button = QPushButton('Quit', self)
                button.clicked.connect(QCoreApplication.instance().quit)
                button.resize(button.sizeHint())
                button.setToolTip('This is a <b>THINGAMAJIG</b> widget')
                button.move(50, 50)

                self.setGeometry(600, 600, 500, 300)
                self.setWindowTitle('Tooltip and Quit Button')
                self.show()


if __name__ == '__main__':
        
        app = QApplication(sys.argv)
        ex = Example()
        sys.exit(app.exec())


