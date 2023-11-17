#include <iostream>
#include <string>
#include <vector>

// Оголошення класу Посередник
class Mediator;

// Оголошення класу Компонент
class Component {
public:
    virtual void setMediator(Mediator* mediator) = 0;
    virtual void receiveMessage(const std::string& message) = 0;
    // Додайте інші методи, які можуть бути потрібні
};

// Оголошення класу Календар
class Calendar : public Component {
public:
    void chooseDate(const std::string& date);
    void chooseTimeSlot(const std::string& timeSlot);
    // Додайте інші методи, які можуть бути потрібні
};

// Оголошення класу Форма Доставки
class DeliveryForm : public Component {
public:
    void toggleRecipientInfo(bool isChecked);
    void provideRecipientInfo(const std::string& name, const std::string& phoneNumber);
    void enableDeliveryInfo(bool isEnabled);
    // Додайте інші методи, які можуть бути потрібні
};

// Оголошення класу Магазин
class FlowerShop : public Component {
public:
    void enableSelfPickup(bool isEnabled);
    // Додайте інші методи, які можуть бути потрібні
};

// Оголошення класу Посередник
class Mediator {
public:
    virtual void notify(Component* sender, const std::string& message) = 0;
    // Додайте інші методи, які можуть бути потрібні
};

// Реалізація класу Конкретний Посередник
class ConcreteMediator : public Mediator {
public:
    void setCalendar(Calendar* calendar);
    void setDeliveryForm(DeliveryForm* deliveryForm);
    void setFlowerShop(FlowerShop* flowerShop);

    virtual void notify(Component* sender, const std::string& message) override;
    // Додайте інші методи, які можуть бути потрібні
};

// Клієнтський код, який використовує патерн Посередник
int main() {
    // Створення об'єктів для календаря, форми доставки та магазину
    // ...

    // Створення екземпляра конкретного посередника
    ConcreteMediator mediator;

    // Встановлення посередника для кожного компонента
    mediator.setCalendar(&calendar);
    mediator.setDeliveryForm(&deliveryForm);
    mediator.setFlowerShop(&flowerShop);

    // Використання компонентів через посередника
    // ...

    return 0;
}
