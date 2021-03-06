/***********************************************************************************
** MIT License                                                                    **
**                                                                                **
** Copyright (c) 2018 Victor DENIS (victordenis01@gmail.com)                      **
**                                                                                **
** Permission is hereby granted, free of charge, to any person obtaining a copy   **
** of this software and associated documentation files (the "Software"), to deal  **
** in the Software without restriction, including without limitation the rights   **
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell      **
** copies of the Software, and to permit persons to whom the Software is          **
** furnished to do so, subject to the following conditions:                       **
**                                                                                **
** The above copyright notice and this permission notice shall be included in all **
** copies or substantial portions of the Software.                                **
**                                                                                **
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR     **
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,       **
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE    **
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER         **
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  **
** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  **
** SOFTWARE.                                                                      **
***********************************************************************************/

#pragma once
#ifndef SIELOBROWSER_TABICON_HPP
#define SIELOBROWSER_TABICON_HPP

#include <QWidget>
#include <QImage>
#include <QIcon>

#include <QTimer>

#include <QPaintEvent>
#include <QMouseEvent>

namespace Sn {
class WebTab;

class TabIcon: public QWidget {
Q_OBJECT

public:
	TabIcon(QWidget* parent = nullptr);

	void setWebTab(WebTab* tab);
	void updateIcon();

signals:
	void resized();

private slots:
	void showLoadingAnimation();
	void hideLoadingAnimation();

	void updateAudioIcon(bool recentlyAudible);
	void updateAnimationFrame();

private:
	void show();
	void hide();
	bool shouldBeVisible() const;

	void paintEvent(QPaintEvent* event);
	void mousePressEvent(QMouseEvent* event);

	WebTab* m_tab{nullptr};
	QTimer* m_updateTimer{nullptr};
	QTimer* m_hideTimer{nullptr};
	QPixmap m_sitePixmap{};

	int m_currentFrame{0};
	bool m_animationRunning{false};
	bool m_audioIconDisplayed{false};

	struct Data {
		int framesCount{};
		QPixmap animationPixmap{};
		QIcon audioPlayingPixmap{};
		QIcon audioMutedPixmap{};
	};

	static Data* s_data;
};
}
#endif //SIELOBROWSER_TABICON_HPP
