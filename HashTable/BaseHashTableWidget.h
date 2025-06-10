#pragma once

#include <QWidget>

#include "HashTable.h"

QT_BEGIN_NAMESPACE
namespace Ui { class BaseHashTableWidget; }
QT_END_NAMESPACE

/**
 * @brief Базовый класс виждета хеш-таблицы.
 * Содержит элементы управления (добавление/удаление и т.д.).
 * Наследники класса отвечают за реализацию отображения самой таблицы:
 * - HashTableWidget: метод открытой адресации / метод внутренних цепочек
 * - SceneHashTableWidget: метод внешних цепочек.
 */
class BaseHashTableWidget : public QWidget
{
    Q_OBJECT

public:
    BaseHashTableWidget(QWidget *parent = nullptr);
    ~BaseHashTableWidget() override;

protected slots:
    void onValueChanged(int key, const QString &value);
    virtual void addKeyValue() = 0;
    virtual void removeKeyValue() = 0;
    virtual void findKey() = 0;
    virtual void resizeTable() = 0;
    virtual void changeFunction(int index) = 0;

protected:
    Ui::BaseHashTableWidget *ui;

    HashTable<QString> m_hashTable;

    // TODO: добавить поле хеш-таблицы
};
