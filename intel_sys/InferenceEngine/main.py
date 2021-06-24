from PyQt5.QtCore import pyqtSlot
from Engine import *
from Feature import *
from Fact import *
from QtUI import *

import sys

from PyQt5 import QtGui
from PyQt5.QtWidgets import QApplication, QMainWindow, QWidget, QHeaderView, QTableWidgetItem
from PyQt5 import QtWidgets
from PyQt5.QtCore import pyqtSlot, QMetaObject


class MainWindow(QMainWindow):
    def __init__(self, parent=None):
        super(MainWindow, self).__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)

        self.table1 = self.ui.tableWidget1
        self.table1.horizontalHeader().setSectionResizeMode(QHeaderView.Stretch)

        self.table2 = self.ui.tableWidget2
        self.table2.horizontalHeader().setSectionResizeMode(QHeaderView.Stretch)

        self.engine = Engine('intel_sys/InferenceEngine/rules.txt')
        self.rules = self.engine.rules
        self.engine.show()
        self.showRules()
        self.showAttributes()

    def showAttributes(self):
        self.attributes = self.engine.attributes
        for index, attribute in enumerate(self.attributes):
            row = self.table2.rowCount()
            self.table2.insertRow(row)
            self.showAttribute(index, attribute, self.attributes[attribute])

    def flushAttributes(self):
        self.attributes = self.engine.attributes
        for index, attribute in enumerate(self.attributes):
            row = self.table2.rowCount()
            self.showAttribute(index, attribute, self.attributes[attribute])

    def flushRules(self):
        self.engine.init()
        self.rules = self.engine.rules
        for index, rule in enumerate(self.rules):
            row = self.table1.rowCount()
            self.showRule(index, rule.features, rule.fact)

    def showAttribute(self, row, attribute, value):
        self.table2.setItem(row, 0, QtWidgets.QTableWidgetItem(attribute))
        self.table2.setItem(row, 1, QtWidgets.QTableWidgetItem(value))

    def showRules(self):
        for index, rule in enumerate(self.rules):
            row = self.table1.rowCount()
            self.table1.insertRow(row)
            self.showRule(index, rule.features, rule.fact)

    def showRule(self, row, features, fact):
        # self.table.setItem(row, 0, QtWidgets.QTableWidgetItem(str(index)))
        self.table1.setItem(row, 0, QtWidgets.QTableWidgetItem(
            ', '.join(i.text for i in features)))
        self.table1.setItem(row, 1, QtWidgets.QTableWidgetItem(fact.text))

    @pyqtSlot()
    # 正向推理
    def on_pushButton1_clicked(self):
        print('Inference Start!')
        # 获取Attributes
        text = self.ui.textEdit.toPlainText().split(', ')
        print(text)
        # self.engine.initAttributes()
        for t in text:
            if(t != ''):
                attr = t.split(' = ')[0]
                value = t.split(' = ')[1]
                self.engine.set(attr, value)
                print('SET ', attr, ' = ', value)
        fact = self.engine.run()
        result = ', '.join(f for f in fact)
        self.ui.textEdit_2.setText(result)
        self.flushAttributes()

    @pyqtSlot()
    # 清空历史
    def on_pushButton2_clicked(self):
        print('Cleaning History!')
        self.engine.init()
        self.flushAttributes()
        self.flushRules()

    @pyqtSlot(int, int, int, int)
    def on_tableWidget1_currentCellChanged(self, x, y, row, w):
        if row != -1:
            features = self.table1.item(row, 0).text()
            fact = self.table1.item(row, 1).text()
            text = features + ' -> ' + fact
            rule = Rule(text)
            self.engine.changeRule(row, rule)
            self.rules = self.engine.rules
            print('Rule has been changed successfully!')

    @pyqtSlot(int, int, int, int)
    def on_tableWidget2_currentCellChanged(self, x, y, row, w):
        if row != -1:
            attribute = self.table2.item(row, 0).text()
            value = self.table2.item(row, 1).text()
            self.engine.set(attribute, value)
            self.engine.initAvailableRules()
            print('Attribute has been changed successfully!')


if __name__ == '__main__':
    app = QApplication(sys.argv)
    my = MainWindow()
    my.show()
    app.exec_()
