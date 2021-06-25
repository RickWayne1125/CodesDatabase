from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(1200, 750)
        MainWindow.setStyleSheet("QPushButton{\n"
                                 "    \n"
                                 "    border-radius:15px;\n"
                                 "    background:rgb(0, 174, 255);\n"
                                 "    font: 15pt \"宋体\";\n"
                                 "    icon-size:20px;\n"
                                 "\n"
                                 "}\n"
                                 "\n"
                                 "QLabel{\n"
                                 "\n"
                                 "    font: 15pt \"宋体\";\n"
                                 "\n"
                                 "}\n"
                                 "\n"
                                 "QTextEdit{\n"
                                 "\n"
                                 "    font: 15pt \"宋体\";\n"
                                 "\n"
                                 "}\n"
                                 "")
        self.widget = QtWidgets.QWidget(MainWindow)
        self.widget.setObjectName("widget")
        self.label = QtWidgets.QLabel(self.widget)
        self.label.setGeometry(QtCore.QRect(-10, 30, 191, 71))
        self.label.setLayoutDirection(QtCore.Qt.RightToLeft)
        self.label.setAlignment(
            QtCore.Qt.AlignRight | QtCore.Qt.AlignTrailing | QtCore.Qt.AlignVCenter)
        self.label.setObjectName("label")
        self.textEdit = QtWidgets.QTextEdit(self.widget)
        self.textEdit.setGeometry(QtCore.QRect(200, 30, 800, 90))
        self.textEdit.setObjectName("textEdit")
        # Infer Button
        self.pushButton1 = QtWidgets.QPushButton(self.widget)
        self.pushButton1.setGeometry(QtCore.QRect(1010, 30, 180, 90))
        self.pushButton1.setStyleSheet("background-color: rgb(0, 191, 255);")
        self.pushButton1.setAutoRepeatInterval(100)
        self.pushButton1.setObjectName("pushButton1")
        # Clear Button
        self.pushButton2 = QtWidgets.QPushButton(self.widget)
        self.pushButton2.setGeometry(QtCore.QRect(1010, 130, 180, 90))
        self.pushButton2.setStyleSheet("background-color: rgb(0, 191, 255);")
        self.pushButton2.setAutoRepeatInterval(100)
        self.pushButton2.setObjectName("pushButton2")
        # Result Label
        self.label_2 = QtWidgets.QLabel(self.widget)
        self.label_2.setGeometry(QtCore.QRect(0, 150, 181, 51))
        self.label_2.setAutoFillBackground(False)
        self.label_2.setAlignment(
            QtCore.Qt.AlignRight | QtCore.Qt.AlignTrailing | QtCore.Qt.AlignVCenter)
        self.label_2.setObjectName("label_2")
        self.textEdit_2 = QtWidgets.QTextEdit(self.widget)
        self.textEdit_2.setGeometry(QtCore.QRect(200, 130, 800, 90))
        self.textEdit_2.setObjectName("textEdit_2")
        # 添加知识库表
        self.tableWidget1 = QtWidgets.QTableWidget(self.widget)
        self.tableWidget1.setGeometry(QtCore.QRect(20, 230, 1160, 250))
        self.tableWidget1.setFocusPolicy(QtCore.Qt.StrongFocus)
        self.tableWidget1.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.tableWidget1.setLineWidth(34)
        self.tableWidget1.setVerticalScrollBarPolicy(
            QtCore.Qt.ScrollBarAsNeeded)
        self.tableWidget1.setHorizontalScrollBarPolicy(
            QtCore.Qt.ScrollBarAsNeeded)
        self.tableWidget1.setSizeAdjustPolicy(
            QtWidgets.QAbstractScrollArea.AdjustToContents)
        self.tableWidget1.setAlternatingRowColors(True)
        self.tableWidget1.setHorizontalScrollMode(
            QtWidgets.QAbstractItemView.ScrollPerPixel)
        self.tableWidget1.setGridStyle(QtCore.Qt.CustomDashLine)
        self.tableWidget1.setWordWrap(True)
        self.tableWidget1.setRowCount(0)
        self.tableWidget1.setColumnCount(2)
        self.tableWidget1.setObjectName("tableWidget1")
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget1.setHorizontalHeaderItem(0, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget1.setHorizontalHeaderItem(1, item)
        self.tableWidget1.horizontalHeader().setVisible(True)
        self.tableWidget1.horizontalHeader().setCascadingSectionResizes(True)
        self.tableWidget1.horizontalHeader().setDefaultSectionSize(300)
        self.tableWidget1.horizontalHeader().setHighlightSections(True)
        self.tableWidget1.horizontalHeader().setMinimumSectionSize(145)
        self.tableWidget1.horizontalHeader().setSortIndicatorShown(True)
        self.tableWidget1.horizontalHeader().setStretchLastSection(True)
        self.tableWidget1.verticalHeader().setCascadingSectionResizes(True)
        self.tableWidget1.verticalHeader().setSortIndicatorShown(False)
        self.tableWidget1.verticalHeader().setStretchLastSection(False)
        # 添加属性表
        self.tableWidget2 = QtWidgets.QTableWidget(self.widget)
        self.tableWidget2.setGeometry(QtCore.QRect(20, 490, 1160, 250))
        self.tableWidget2.setFocusPolicy(QtCore.Qt.StrongFocus)
        self.tableWidget2.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.tableWidget2.setLineWidth(34)
        self.tableWidget2.setVerticalScrollBarPolicy(
            QtCore.Qt.ScrollBarAsNeeded)
        self.tableWidget2.setHorizontalScrollBarPolicy(
            QtCore.Qt.ScrollBarAsNeeded)
        self.tableWidget2.setSizeAdjustPolicy(
            QtWidgets.QAbstractScrollArea.AdjustToContents)
        self.tableWidget2.setAlternatingRowColors(True)
        self.tableWidget2.setHorizontalScrollMode(
            QtWidgets.QAbstractItemView.ScrollPerPixel)
        self.tableWidget2.setGridStyle(QtCore.Qt.CustomDashLine)
        self.tableWidget2.setWordWrap(True)
        self.tableWidget2.setRowCount(0)
        self.tableWidget2.setColumnCount(2)
        self.tableWidget2.setObjectName("tableWidget2")
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget2.setHorizontalHeaderItem(0, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget2.setHorizontalHeaderItem(1, item)
        self.tableWidget2.horizontalHeader().setVisible(True)
        self.tableWidget2.horizontalHeader().setCascadingSectionResizes(True)
        self.tableWidget2.horizontalHeader().setDefaultSectionSize(300)
        self.tableWidget2.horizontalHeader().setHighlightSections(True)
        self.tableWidget2.horizontalHeader().setMinimumSectionSize(145)
        self.tableWidget2.horizontalHeader().setSortIndicatorShown(True)
        self.tableWidget2.horizontalHeader().setStretchLastSection(True)
        self.tableWidget2.verticalHeader().setCascadingSectionResizes(True)
        self.tableWidget2.verticalHeader().setSortIndicatorShown(False)
        self.tableWidget2.verticalHeader().setStretchLastSection(False)

        MainWindow.setCentralWidget(self.widget)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "Inference Engine"))
        self.label.setText(_translate("MainWindow", "输入事实"))
        self.textEdit.setPlaceholderText(
            _translate("MainWindow", "条件之间使用', '分割"))
        self.pushButton1.setText(_translate("MainWindow", "开始推理"))
        self.pushButton2.setText(_translate("MainWindow", "清空记录"))
        self.label_2.setText(_translate("MainWindow", "推理结果"))
        item = self.tableWidget1.horizontalHeaderItem(0)
        item.setText(_translate("MainWindow", "Features"))
        item = self.tableWidget1.horizontalHeaderItem(1)
        item.setText(_translate("MainWindow", "Fact"))
        item = self.tableWidget2.horizontalHeaderItem(0)
        item.setText(_translate("MainWindow", "Attributes"))
        item = self.tableWidget2.horizontalHeaderItem(1)
        item.setText(_translate("MainWindow", "Value"))
