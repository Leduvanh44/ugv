/********************************************************************************
** Form generated from reading UI file 'PlotData.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLOTDATA_H
#define UI_PLOTDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QPushButton *Heading_btn;
    QPushButton *CTE_btn;
    QPushButton *ATE_btn;
    QPushButton *Velleft_btn;
    QPushButton *Vel_btn;
    QStackedWidget *Plot_page;
    QCustomPlot *Heading_customPlot;
    QCustomPlot *CTE_customPlot;
    QCustomPlot *ATE_customPlot;
    QWidget *Vel_customPlot;
    QVBoxLayout *verticalLayout_2;
    QCustomPlot *Vel_left_customPlot;
    QCustomPlot *Vel_right_customPlot;
    QCustomPlot *Velocity_customPlot;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(912, 604);
        horizontalLayout = new QHBoxLayout(Form);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(Form);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setStyleSheet(QLatin1String("*{\n"
"	color: rgb(211, 215, 207);\n"
"}\n"
"QPushButton#Heading_btn{\n"
"	color: rgb(0, 0, 0);\n"
"}"));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Heading_btn = new QPushButton(frame);
        Heading_btn->setObjectName(QStringLiteral("Heading_btn"));
        Heading_btn->setMaximumSize(QSize(16777215, 50));
        Heading_btn->setFlat(true);

        verticalLayout->addWidget(Heading_btn);

        CTE_btn = new QPushButton(frame);
        CTE_btn->setObjectName(QStringLiteral("CTE_btn"));
        CTE_btn->setMaximumSize(QSize(16777215, 50));
        CTE_btn->setFlat(true);

        verticalLayout->addWidget(CTE_btn);

        ATE_btn = new QPushButton(frame);
        ATE_btn->setObjectName(QStringLiteral("ATE_btn"));
        ATE_btn->setMaximumSize(QSize(16777215, 50));
        ATE_btn->setFlat(true);

        verticalLayout->addWidget(ATE_btn);

        Velleft_btn = new QPushButton(frame);
        Velleft_btn->setObjectName(QStringLiteral("Velleft_btn"));
        Velleft_btn->setMaximumSize(QSize(16777215, 50));
        Velleft_btn->setFlat(true);

        verticalLayout->addWidget(Velleft_btn);

        Vel_btn = new QPushButton(frame);
        Vel_btn->setObjectName(QStringLiteral("Vel_btn"));
        Vel_btn->setMaximumSize(QSize(16777215, 50));
        Vel_btn->setFlat(true);

        verticalLayout->addWidget(Vel_btn);


        horizontalLayout->addWidget(frame);

        Plot_page = new QStackedWidget(Form);
        Plot_page->setObjectName(QStringLiteral("Plot_page"));
        Heading_customPlot = new QCustomPlot();
        Heading_customPlot->setObjectName(QStringLiteral("Heading_customPlot"));
        Plot_page->addWidget(Heading_customPlot);
        CTE_customPlot = new QCustomPlot();
        CTE_customPlot->setObjectName(QStringLiteral("CTE_customPlot"));
        Plot_page->addWidget(CTE_customPlot);
        ATE_customPlot = new QCustomPlot();
        ATE_customPlot->setObjectName(QStringLiteral("ATE_customPlot"));
        Plot_page->addWidget(ATE_customPlot);
        Vel_customPlot = new QWidget();
        Vel_customPlot->setObjectName(QStringLiteral("Vel_customPlot"));
        verticalLayout_2 = new QVBoxLayout(Vel_customPlot);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        Vel_left_customPlot = new QCustomPlot(Vel_customPlot);
        Vel_left_customPlot->setObjectName(QStringLiteral("Vel_left_customPlot"));

        verticalLayout_2->addWidget(Vel_left_customPlot);

        Vel_right_customPlot = new QCustomPlot(Vel_customPlot);
        Vel_right_customPlot->setObjectName(QStringLiteral("Vel_right_customPlot"));

        verticalLayout_2->addWidget(Vel_right_customPlot);

        Plot_page->addWidget(Vel_customPlot);
        Velocity_customPlot = new QCustomPlot();
        Velocity_customPlot->setObjectName(QStringLiteral("Velocity_customPlot"));
        Plot_page->addWidget(Velocity_customPlot);

        horizontalLayout->addWidget(Plot_page);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 8);

        retranslateUi(Form);

        Heading_btn->setDefault(false);


        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", Q_NULLPTR));
        Heading_btn->setText(QApplication::translate("Form", "Heading", Q_NULLPTR));
        CTE_btn->setText(QApplication::translate("Form", "CrossTrack_Error", Q_NULLPTR));
        ATE_btn->setText(QApplication::translate("Form", "AlongTrack_Error", Q_NULLPTR));
        Velleft_btn->setText(QApplication::translate("Form", "Angular_vel", Q_NULLPTR));
        Vel_btn->setText(QApplication::translate("Form", "Velocity", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLOTDATA_H
