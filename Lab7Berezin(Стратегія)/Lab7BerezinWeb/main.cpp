#include <iostream>

// Інтерфейс стратегії для розрахунку вартості доставки
class DeliveryStrategy {
public:
    virtual double calculateCost(double orderAmount) const = 0;
    virtual ~DeliveryStrategy() = default;
};

// Конкретна стратегія для самовивозу
class PickupStrategy : public DeliveryStrategy {
public:
    double calculateCost(double orderAmount) const override {
        // Розрахунок вартості для самовивозу
        // ...
    }
};

// Конкретна стратегія для доставки зовнішньою службою доставки
class ExternalDeliveryStrategy : public DeliveryStrategy {
public:
    double calculateCost(double orderAmount) const override {
        // Розрахунок вартості для доставки зовнішньою службою
        // ...
    }
};

// Конкретна стратегія для доставки власною службою доставки
class OwnDeliveryStrategy : public DeliveryStrategy {
public:
    double calculateCost(double orderAmount) const override {
        // Розрахунок вартості для доставки власною службою
        // ...
    }
};

// Клас контексту, який використовує стратегію
class DeliveryContext {
private:
    DeliveryStrategy* deliveryStrategy;

public:
    DeliveryContext(DeliveryStrategy* strategy) : deliveryStrategy(strategy) {}

    void setDeliveryStrategy(DeliveryStrategy* strategy) {
        deliveryStrategy = strategy;
    }

    double calculateDeliveryCost(double orderAmount) const {
        // Використання поточної стратегії для розрахунку вартості
        return deliveryStrategy->calculateCost(orderAmount);
    }
};

int main() {
    // Створення об'єктів стратегій
    PickupStrategy pickupStrategy;
    ExternalDeliveryStrategy externalDeliveryStrategy;
    OwnDeliveryStrategy ownDeliveryStrategy;

    // Створення контексту доставки з початковою стратегією (наприклад, самовивіз)
    DeliveryContext deliveryContext(&pickupStrategy);

    // Розрахунок вартості для різних способів доставки
    double orderAmount = 50.0;
    double pickupCost = deliveryContext.calculateDeliveryCost(orderAmount);

    // Зміна стратегії (наприклад, на зовнішню доставку)
    deliveryContext.setDeliveryStrategy(&externalDeliveryStrategy);
    double externalDeliveryCost = deliveryContext.calculateDeliveryCost(orderAmount);

    // Зміна стратегії (наприклад, на власну доставку)
    deliveryContext.setDeliveryStrategy(&ownDeliveryStrategy);
    double ownDeliveryCost = deliveryContext.calculateDeliveryCost(orderAmount);

    return 0;
}
