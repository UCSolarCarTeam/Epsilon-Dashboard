#pragma once
#include "I_FaultUi.h"
#include "FontLoader/FontLoader.h"
namespace Ui
{
    class FaultUi;
}
class FaultUi : public I_FaultUi
{
    Q_OBJECT
public:
    explicit FaultUi();
    ~FaultUi();

    QWidget& motor0ContentsWidget();
    QWidget& motor1ContentsWidget();
    QWidget& batteryContentsWidget();

    QScrollArea& motor0ScrollArea();
    QScrollArea& motor1ScrollArea();
    QScrollArea& batteryScrollArea();

    QLabel& showHistoryLabel();

private:
    Ui::FaultUi* ui_;
    QScopedPointer<FontLoader> fontLoader_;
};
