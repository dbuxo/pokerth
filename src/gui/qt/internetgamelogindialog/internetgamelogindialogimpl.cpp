#include "internetgamelogindialogimpl.h"
#include "configfile.h"
#include <QtCore>

internetGameLoginDialogImpl::internetGameLoginDialogImpl(QWidget *parent, ConfigFile *c) :
    QDialog(parent), myConfig(c){
    setupUi(this);
	
	connect(groupBox_reguser, SIGNAL(toggled(bool)), this, SLOT(regUserToggled(bool)));
	connect(checkBox_guest, SIGNAL(toggled(bool)), this, SLOT(guestUserToggled(bool)));
	connect(lineEdit_password, SIGNAL(textEdited(QString)), this, SLOT(okButtonCheck()));
	connect(lineEdit_username, SIGNAL(textEdited(QString)), this, SLOT(okButtonCheck()));
}

void internetGameLoginDialogImpl::regUserToggled(bool b) {
	
	checkBox_guest->setChecked(!b);
}

void internetGameLoginDialogImpl::guestUserToggled(bool b) {

	groupBox_reguser->setChecked(!b);
	
	if(b) {
		checkBox_rememberPassword->setChecked(false);
		lineEdit_password->clear();
		lineEdit_username->clear();
	}	
}

void internetGameLoginDialogImpl::exec() {

	if(myConfig->readConfigInt("InternetLoginMode") == 0) {
		groupBox_reguser->setChecked(true);
		lineEdit_username->setText(QString::fromUtf8(myConfig->readConfigString("InternetLoginUserName").c_str()));
		if(myConfig->readConfigInt("InternetSavePassword")) {
			checkBox_rememberPassword->setChecked(true);
			lineEdit_password->setText(QString::fromUtf8(QByteArray::fromBase64(myConfig->readConfigString("InternetLoginPassword").c_str())));
		}
		else {
			checkBox_rememberPassword->setChecked(false);
			lineEdit_password->clear();
		}
	}
	else {
		checkBox_guest->setChecked(true);
	}
	
	okButtonCheck();
	
	if(groupBox_reguser->isChecked() && !checkBox_rememberPassword->isChecked() && lineEdit_password->text().isEmpty()) {
		lineEdit_password->setFocus();
	}
	
	QDialog::exec();
}

void internetGameLoginDialogImpl::accept() {

	if(groupBox_reguser->isChecked()) {
		myConfig->writeConfigInt("InternetLoginMode", 0);
		myConfig->writeConfigString("InternetLoginUserName", lineEdit_username->text().toUtf8().constData());
		if(checkBox_rememberPassword->isChecked()) {
			myConfig->writeConfigInt("InternetSavePassword", 1);
			myConfig->writeConfigString("InternetLoginPassword", lineEdit_password->text().toUtf8().toBase64().constData());
		}
		else {
			myConfig->writeConfigInt("InternetSavePassword", 0);
		}
	}
	else {
		myConfig->writeConfigInt("InternetLoginMode", 1);
	}
	
	myConfig->writeBuffer();
	
	QDialog::accept();
} 

void internetGameLoginDialogImpl::okButtonCheck() {
	
	if(groupBox_reguser->isChecked()) {
		if(!lineEdit_password->text().isEmpty() && !lineEdit_username->text().isEmpty()) {
			pushButton_login->setEnabled(true);
		}
		else {
			pushButton_login->setEnabled(false);
		}
	}
	else {
		pushButton_login->setEnabled(true);
	}
}
