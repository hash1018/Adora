

#include "WritingSettingWidget.h"
#include "Base/LanguageManager.h"
#include "Base/SettingManager.h"
#include "Base/Hotkey.h"

WritingSettingWidget::WritingSettingWidget(QWidget *parent)
	:AbstractStackWidget(parent) {

	ui.setupUi(this);

	QString str = "<b>" + getLanUiValue("MenuWriting/Writing") + "</b>";
	ui.writingLabel->setTextFormat(Qt::RichText);
	ui.writingLabel->setText(str);


	ui.useCursorHotkeyCheckBox->setText(getLanUiValue("MenuWriting/Cursor Hotkey"));
	ui.usePencilHotkeyCheckBox->setText(getLanUiValue("MenuWriting/Pencil Hotkey"));
	ui.useHighlightHotkeyCheckBox->setText(getLanUiValue("MenuWriting/Highlighter Hotkey"));
	ui.useLineHotkeyCheckBox->setText(getLanUiValue("MenuWriting/Line Hotkey"));
	ui.useArrowLineHotkeyCheckBox->setText(getLanUiValue("MenuWriting/ArrowLine Hotkey"));
	ui.useNumberingHotkeyCheckBox->setText(getLanUiValue("MenuWriting/Numbering Hotkey"));
	ui.useEraserHotkeyCheckBox->setText(getLanUiValue("MenuWriting/Eraser Hotkey"));
	ui.useDeleteAllHotkeyCheckBox->setText(getLanUiValue("MenuWriting/DeleteAll Hotkey"));



	////////
	ui.useCursorHotkeyCheckBox->setChecked(SettingManager::getInstance()->getWritingSetting()->getUseCursorHotkey());
	ui.cursorHotkeyLineEdit->setDisabled(!SettingManager::getInstance()->getWritingSetting()->getUseCursorHotkey());

	if (SettingManager::getInstance()->getWritingSetting()->getCursorHotkey().isEmpty() == false) {

		Hotkey *hotkey = new Hotkey(SettingManager::getInstance()->getWritingSetting()->getCursorHotkey());
		hotkey->setType(HotkeyType::HotkeyType_Cursor);
		ui.cursorHotkeyLineEdit->load(hotkey);
	}
	///////

	ui.usePencilHotkeyCheckBox->setChecked(SettingManager::getInstance()->getWritingSetting()->getUsePencilHotkey());
	ui.pencilHotkeyLineEdit->setDisabled(!SettingManager::getInstance()->getWritingSetting()->getUsePencilHotkey());

	if (SettingManager::getInstance()->getWritingSetting()->getPencilHotkey().isEmpty() == false) {

		Hotkey *hotkey = new Hotkey(SettingManager::getInstance()->getWritingSetting()->getPencilHotkey());
		hotkey->setType(HotkeyType::HotkeyType_Pencil);
		ui.pencilHotkeyLineEdit->load(hotkey);
	}
	///////

	ui.useHighlightHotkeyCheckBox->setChecked(SettingManager::getInstance()->getWritingSetting()->getUseHighlightHotkey());
	ui.highlightHotkeyLineEdit->setDisabled(!SettingManager::getInstance()->getWritingSetting()->getUseHighlightHotkey());

	if (SettingManager::getInstance()->getWritingSetting()->getHighlightHotkey().isEmpty() == false) {

		Hotkey *hotkey = new Hotkey(SettingManager::getInstance()->getWritingSetting()->getHighlightHotkey());
		hotkey->setType(HotkeyType::HotkeyType_Highlighter);
		ui.highlightHotkeyLineEdit->load(hotkey);
	}

	////////


	ui.useLineHotkeyCheckBox->setChecked(SettingManager::getInstance()->getWritingSetting()->getUseLineHotkey());
	ui.lineHotkeyLineEdit->setDisabled(!SettingManager::getInstance()->getWritingSetting()->getUseLineHotkey());

	if (SettingManager::getInstance()->getWritingSetting()->getLineHotkey().isEmpty() == false) {

		Hotkey *hotkey = new Hotkey(SettingManager::getInstance()->getWritingSetting()->getLineHotkey());
		hotkey->setType(HotkeyType::HotkeyType_Line);
		ui.lineHotkeyLineEdit->load(hotkey);
	}

	////////

	ui.useArrowLineHotkeyCheckBox->setChecked(SettingManager::getInstance()->getWritingSetting()->getUseArrowLineHotkey());
	ui.arrowLineHotkeyLineEdit->setDisabled(!SettingManager::getInstance()->getWritingSetting()->getUseArrowLineHotkey());

	if (SettingManager::getInstance()->getWritingSetting()->getArrowLineHotkey().isEmpty() == false) {

		Hotkey *hotkey = new Hotkey(SettingManager::getInstance()->getWritingSetting()->getArrowLineHotkey());
		hotkey->setType(HotkeyType::HotkeyType_ArrowLine);
		ui.arrowLineHotkeyLineEdit->load(hotkey);
	}


	/////////


	ui.useNumberingHotkeyCheckBox->setChecked(SettingManager::getInstance()->getWritingSetting()->getUseNumberingHotkey());
	ui.numberingHotkeyLineEdit->setDisabled(!SettingManager::getInstance()->getWritingSetting()->getUseNumberingHotkey());

	if (SettingManager::getInstance()->getWritingSetting()->getNumberingHotkey().isEmpty() == false) {

		Hotkey *hotkey = new Hotkey(SettingManager::getInstance()->getWritingSetting()->getNumberingHotkey());
		hotkey->setType(HotkeyType::HotkeyType_Numbering);
		ui.numberingHotkeyLineEdit->load(hotkey);
	}

	/////////

	ui.useEraserHotkeyCheckBox->setChecked(SettingManager::getInstance()->getWritingSetting()->getUseEraserHotkey());
	ui.eraserHotkeyLineEdit->setDisabled(!SettingManager::getInstance()->getWritingSetting()->getUseEraserHotkey());

	if (SettingManager::getInstance()->getWritingSetting()->getEraserHotkey().isEmpty() == false) {

		Hotkey *hotkey = new Hotkey(SettingManager::getInstance()->getWritingSetting()->getEraserHotkey());
		hotkey->setType(HotkeyType::HotkeyType_Eraser);
		ui.eraserHotkeyLineEdit->load(hotkey);
	}
	

	//////////

	ui.useDeleteAllHotkeyCheckBox->setChecked(SettingManager::getInstance()->getWritingSetting()->getUseDeleteAllHotkey());
	ui.deleteAllHotkeyLineEdit->setDisabled(!SettingManager::getInstance()->getWritingSetting()->getUseDeleteAllHotkey());

	if (SettingManager::getInstance()->getWritingSetting()->getDeleteAllHotkey().isEmpty() == false) {

		Hotkey *hotkey = new Hotkey(SettingManager::getInstance()->getWritingSetting()->getDeleteAllHotkey());
		hotkey->setType(HotkeyType::HotkeyType_DeleteAll);
		ui.deleteAllHotkeyLineEdit->load(hotkey);
	}



	connect(ui.useCursorHotkeyCheckBox, &QCheckBox::toggled, this, &WritingSettingWidget::cursorHotkeyCheckBoxToggled);
	connect(ui.cursorHotkeyLineEdit, &HotkeyLineEdit::hotkeyEmitted, this, &WritingSettingWidget::cursorHotkeyEmitted);

	connect(ui.usePencilHotkeyCheckBox, &QCheckBox::toggled, this, &WritingSettingWidget::pencilHotkeyCheckBoxToggled);
	connect(ui.pencilHotkeyLineEdit, &HotkeyLineEdit::hotkeyEmitted, this, &WritingSettingWidget::pencilHotkeyEmitted);

	connect(ui.useHighlightHotkeyCheckBox, &QCheckBox::toggled, this, &WritingSettingWidget::highlightHotkeyCheckBoxToggled);
	connect(ui.highlightHotkeyLineEdit, &HotkeyLineEdit::hotkeyEmitted, this, &WritingSettingWidget::highlightHotkeyEmitted);

	connect(ui.useLineHotkeyCheckBox, &QCheckBox::toggled, this, &WritingSettingWidget::lineHotkeyCheckBoxToggled);
	connect(ui.lineHotkeyLineEdit, &HotkeyLineEdit::hotkeyEmitted, this, &WritingSettingWidget::lineHotkeyEmitted);

	connect(ui.useArrowLineHotkeyCheckBox, &QCheckBox::toggled, this, &WritingSettingWidget::arrowLineHotkeyCheckBoxToggled);
	connect(ui.arrowLineHotkeyLineEdit, &HotkeyLineEdit::hotkeyEmitted, this, &WritingSettingWidget::arrowLineHotkeyEmitted);

	connect(ui.useNumberingHotkeyCheckBox, &QCheckBox::toggled, this, &WritingSettingWidget::numberingHotkeyCheckBoxToggled);
	connect(ui.numberingHotkeyLineEdit, &HotkeyLineEdit::hotkeyEmitted, this, &WritingSettingWidget::numberingHotkeyEmitted);

	connect(ui.useEraserHotkeyCheckBox, &QCheckBox::toggled, this, &WritingSettingWidget::eraserHotkeyCheckBoxToggled);
	connect(ui.eraserHotkeyLineEdit, &HotkeyLineEdit::hotkeyEmitted, this, &WritingSettingWidget::eraserHotkeyEmitted);

	connect(ui.useDeleteAllHotkeyCheckBox, &QCheckBox::toggled, this, &WritingSettingWidget::deleteAllHotkeyCheckBoxToggled);
	connect(ui.deleteAllHotkeyLineEdit, &HotkeyLineEdit::hotkeyEmitted, this, &WritingSettingWidget::deleteAllHotkeyEmitted);

}

WritingSettingWidget::~WritingSettingWidget() {

}


void WritingSettingWidget::cursorHotkeyCheckBoxToggled(bool checked) {

	SettingManager::getInstance()->getWritingSetting()->setUseCursorHotkey(checked);
	ui.cursorHotkeyLineEdit->setDisabled(!checked);
}

void WritingSettingWidget::cursorHotkeyEmitted(const QKeySequence &keySequence) {

	SettingManager::getInstance()->getWritingSetting()->setCursorHotkey(keySequence);
	int index = HotkeyList::getInstance()->indexOf(keySequence);
	HotkeyList::getInstance()->at(index)->setType(HotkeyType::HotkeyType_Cursor);
}


void WritingSettingWidget::pencilHotkeyCheckBoxToggled(bool checked) {

	SettingManager::getInstance()->getWritingSetting()->setUsePencilHotkey(checked);
	ui.pencilHotkeyLineEdit->setDisabled(!checked);
}

void WritingSettingWidget::pencilHotkeyEmitted(const QKeySequence &keySequence) {

	SettingManager::getInstance()->getWritingSetting()->setPencilHotkey(keySequence);
	int index = HotkeyList::getInstance()->indexOf(keySequence);
	HotkeyList::getInstance()->at(index)->setType(HotkeyType::HotkeyType_Pencil);
}


void WritingSettingWidget::highlightHotkeyCheckBoxToggled(bool checked) {

	SettingManager::getInstance()->getWritingSetting()->setUseHighlightHotkey(checked);
	ui.highlightHotkeyLineEdit->setDisabled(!checked);
}

void WritingSettingWidget::highlightHotkeyEmitted(const QKeySequence &keySequence) {

	SettingManager::getInstance()->getWritingSetting()->setHighlightHotkey(keySequence);
	int index = HotkeyList::getInstance()->indexOf(keySequence);
	HotkeyList::getInstance()->at(index)->setType(HotkeyType::HotkeyType_Highlighter);
}


void WritingSettingWidget::lineHotkeyCheckBoxToggled(bool checked) {

	SettingManager::getInstance()->getWritingSetting()->setUseLineHotkey(checked);
	ui.lineHotkeyLineEdit->setDisabled(!checked);
}

void WritingSettingWidget::lineHotkeyEmitted(const QKeySequence &keySequence) {

	SettingManager::getInstance()->getWritingSetting()->setLineHotkey(keySequence);
	int index = HotkeyList::getInstance()->indexOf(keySequence);
	HotkeyList::getInstance()->at(index)->setType(HotkeyType::HotkeyType_Line);
}


void WritingSettingWidget::arrowLineHotkeyCheckBoxToggled(bool checked) {

	SettingManager::getInstance()->getWritingSetting()->setUseArrowLineHotkey(checked);
	ui.arrowLineHotkeyLineEdit->setDisabled(!checked);
}

void WritingSettingWidget::arrowLineHotkeyEmitted(const QKeySequence &keySequence) {

	SettingManager::getInstance()->getWritingSetting()->setArrowLineHotkey(keySequence);
	int index = HotkeyList::getInstance()->indexOf(keySequence);
	HotkeyList::getInstance()->at(index)->setType(HotkeyType::HotkeyType_ArrowLine);

}

void WritingSettingWidget::numberingHotkeyCheckBoxToggled(bool checked) {

	SettingManager::getInstance()->getWritingSetting()->setUseNumberingHotkey(checked);
	ui.numberingHotkeyLineEdit->setDisabled(!checked);
}

void WritingSettingWidget::numberingHotkeyEmitted(const QKeySequence &keySequence) {

	SettingManager::getInstance()->getWritingSetting()->setNumberingHotkey(keySequence);
	int index = HotkeyList::getInstance()->indexOf(keySequence);
	HotkeyList::getInstance()->at(index)->setType(HotkeyType::HotkeyType_Numbering);
}


void WritingSettingWidget::eraserHotkeyCheckBoxToggled(bool checked) {

	SettingManager::getInstance()->getWritingSetting()->setUseEraserHotkey(checked);
	ui.eraserHotkeyLineEdit->setDisabled(!checked);
}

void WritingSettingWidget::eraserHotkeyEmitted(const QKeySequence &keySequence) {

	SettingManager::getInstance()->getWritingSetting()->setEraserHotkey(keySequence);
	int index = HotkeyList::getInstance()->indexOf(keySequence);
	HotkeyList::getInstance()->at(index)->setType(HotkeyType::HotkeyType_Eraser);
}


void WritingSettingWidget::deleteAllHotkeyCheckBoxToggled(bool checked) {

	SettingManager::getInstance()->getWritingSetting()->setUseDeleteAllHotkey(checked);
	ui.deleteAllHotkeyLineEdit->setDisabled(!checked);
}

void WritingSettingWidget::deleteAllHotkeyEmitted(const QKeySequence &keySequence) {

	SettingManager::getInstance()->getWritingSetting()->setDeleteAllHotkey(keySequence);
	int index = HotkeyList::getInstance()->indexOf(keySequence);
	HotkeyList::getInstance()->at(index)->setType(HotkeyType::HotkeyType_DeleteAll);
}