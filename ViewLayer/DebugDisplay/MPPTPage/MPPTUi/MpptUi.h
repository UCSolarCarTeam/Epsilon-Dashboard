#pragma once
#include "I_MpptUi.h"

namespace Ui
{
    class MpptUi;
}

class MpptUi : public I_MpptUi
{
    Q_OBJECT
public:
    explicit MpptUi();
    ~MpptUi();
private:
    Ui::MpptUi* ui_;
};

