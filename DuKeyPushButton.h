#include <QPushButton>

#ifndef _QKEYPUSHBUTTON_H
// colori e stile da utilizzare per la tastiera ed i tasti:
#define _QKEYPUSHBUTTON_H

#define DEFAULT_BACKGROUND_BUTTON	"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #8C8F8C, stop: 1 #000000);"
#define CHANGED_BACKGROUND_BUTTON	"background:lightgray;color:darkred;"
//#define DEFAULT_BACKGROUND_BUTTON	"background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,stop: 0 #f6f7fa, stop: 1 #dadbde);"
//#define CHANGED_BACKGROUND_BUTTON	"background:lightblue;"

#define DEFAULT_STYLE_BUTTON            "color:white;border: 1px solid #000000;border-radius:6px;"
//#define DEFAULT_STYLE_BUTTON            "border: 1px solid #8f8f91;border-radius:5px;"
#define STYLE_FOCUS_TEXT                "border: 1px solid red"

//#define DEFAULT_STYLE_BUTTON		"color:white;border: 2px solid black;border-radius:5px;font-weight: bold;font-size:17px;"
//#define DEFAULT_BACKGROUND_BUTTON	"background:gray;"
//#define CHANGED_BACKGROUND_BUTTON	"background:red;"

#define EMBEDDED_KEYBOARD               "font-size:9px"
#define WIDTH_ZOOM_KEY                  20
#define HEIGHT_ZOOM_KEY                 WIDTH_ZOOM_KEY
//
// tasti speciali utilizzati all'interno delle classi:
#define KEY_TAB				tr("TAB")
#define KEY_ALT				tr("ALT")
#define KEY_CAPS			tr("CAPS")
#define KEY_CTRL_LEFT			tr("CTRL")
#define KEY_CUT_LEFT			tr("cut")
#define KEY_COPY			tr("copy")
#define KEY_PASTE			tr("paste")
#define KEY_BACKSPACE			tr("BACKSPACE")        
#define KEY_BACKSPACE_EMBEDDED		"<---"
#define KEY_HIDECHAR                    tr("echo")
#define KEY_HIDECHAR_EMBEDDED           tr("echo")
#define KEY_CANC			tr("CANC")
#define KEY_RETURN			tr("RETURN")
#define KEY_SPACE                       " "
#define KEY_WIDTH_EMBEDDED              26
#define KEY_HEIGHT_EMBEDDED             22
//
// macro parametrizzate per la riduzione del codice:
#define IS_KEY(keyTextPressed, keyValCompare)   (keyTextPressed).contains((keyValCompare), Qt::CaseInsensitive)

#define IS_TAB(text)                            IS_KEY(text, KEY_TAB)
#define IS_ALT(text)                            IS_KEY(text, KEY_ALT)
#define IS_CAPS(text)                           IS_KEY(text, KEY_CAPS)
#define IS_CTRL_LEFT(text)                      IS_KEY(text, KEY_CTRL_LEFT)
#define IS_CUT_LEFT(text)                       IS_KEY(text, KEY_CUT_LEFT)
#define IS_BACK(text)                           IS_KEY(text, KEY_BACKSPACE)
#define IS_BACK_EMB(text)                       IS_KEY(text, KEY_BACKSPACE_EMBEDDED)
#define IS_CANC(text)                           IS_KEY(text, KEY_CANC)
#define IS_RETURN(text)                         IS_KEY(text, KEY_RETURN)
#define IS_SPACE(text)                          IS_KEY(text, KEY_SPACE)
#define IS_PASSWORD(text)                       IS_KEY(text, KEY_HIDECHAR)
#define IS_PASSWORD_EMB(text)                   IS_KEY(text, KEY_HIDECHAR_EMBEDDED)
#define IS_COPY(text)                           IS_KEY(text, KEY_COPY)
#define IS_PASTE(text)                          IS_KEY(text, KEY_PASTE)
#define NO_SPECIAL_KEY(text)                    ((text).length() == 1)

// definizione classe rappresentante un tasto:
class DuKeyPushButton: public QPushButton
{
	Q_OBJECT
public:
    DuKeyPushButton(QWidget *parent = nullptr);
private slots:
    void getKeyPress(bool statusCaps);
signals:
	void pressedKey(bool statusCaps);
private:
	QWidget *m_parent;
	QString style_embedded;
	int m_oldYKey;
protected:
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
};

#endif // _QKEYPUSHBUTTON_H
