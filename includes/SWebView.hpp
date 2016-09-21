#pragma once 

#include <QWidget>
#include <QtWebEngineWidgets>

#include "..\includes\STabWidget.hpp"

class SWebView : public QWebEngineView
{
public:
	SWebView(QWidget* parent = nullptr, QUrl url = QUrl("http://google.fr"));
	~SWebView();

public slots:
	void setFullScreen(QWebEngineFullScreenRequest* request);

private:
	QWidget* m_parent{ nullptr };
};