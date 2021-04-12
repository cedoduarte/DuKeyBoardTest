#ifndef _WIDGETKEYBOARD_H

#define _WIDGETKEYBOARD_H

#include "DuKeyPushButton.h"
#include <QLineEdit>
#include <QClipboard>

class DuKeyBoard: public QWidget
{
	Q_OBJECT
public:
    DuKeyBoard(bool embeddedKeyboard = false, QWidget *activeForm = nullptr,
            QWidget *parent = nullptr);
    ~DuKeyBoard();
	void createKeyboard(void);
	bool isEmbeddedKeyboard(void);
	void setZoomFacility(bool active); // only valid for embedded keyboard
	bool isZoomFacilityEnable(void);

	bool statusEchoMode(void) {
		return (this->m_echoMode);
	}

	void setStatusEchoMode(bool echo) {
		this->m_echoMode = echo;
	}

	void receiptChildKey(QKeyEvent *event, QLineEdit *focusThisControl,
			bool reset = false); // accoglie i tasti premuti

    QLineEdit *currentTextBox(void) {
		return (this->m_currentTextBox);
	}

	void switchKeyEchoMode(QLineEdit *control);
	void enableSwitchingEcho(bool status); // if you don't want control echo from keyboard
	bool isEnabledSwitchingEcho(void); // current status
	void borderFrame(bool visible = true);
public slots:
	void show(QWidget *activeForm);
	void hide(bool noChangeColor);
	void focusThis(QLineEdit *control);
protected:
    virtual void closeEvent(QCloseEvent *event);
private:
    DuKeyBoard(const DuKeyBoard &);
    DuKeyBoard &operator=(const DuKeyBoard&);

    // reinizializza le funzioni base della tastiera
    void init_keyboard(QLineEdit *focusThisControl);
    QLineEdit *setCurrentTextStyle(QLineEdit *control);
    QLineEdit *setDefaultTextStyle(QLineEdit *control);
    DuKeyPushButton *createNewKey(QString keyValue);
    QLineEdit *getNextTextbox(QLineEdit *thisControl = nullptr,
                              bool reset = false);
	void controlKeyEcho(QLineEdit *control);
private:
	QLineEdit m_noFocusPalette; // usata per ripristinare la linetext senza focus
	QWidget *m_nextInput; // punta alla textbox attualmente in focus
	QWidget *m_activeWindow;
	QLineEdit *m_currentTextBox; // mantiene il riferimento alla casella correntemente in uso
	static bool m_created;
	bool m_embeddedKeyboard;
	bool m_echoMode; // status of current text object for echo
	bool m_zoomFacilityEmbedded;
	bool m_enablePasswordEcho; // controls the possibility to change among normal/password echo
	QClipboard *m_clipboard;
};

#endif // _WIDGETKEYBOARD_H
