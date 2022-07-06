//
//  main.cpp
//  state-pattern
//
//  Created by Cristian on 16/04/22.
//

#include <iostream>

class State
{
public:
    virtual std::string get_description() = 0;
    virtual State *get_next_state() = 0;
};

class PurchasedState: public State
{
    State *next_state = nullptr;
public:
    PurchasedState(State *next_state): next_state(next_state) {};
    std::string get_description() override
    {
        return "Current state: PURCHASED - Will be shipping soon\n";
    }
    
    State *get_next_state() override {return next_state;};
};

class InTransitState: public State {
    State *next_state = nullptr;
public:
    InTransitState(State *next_state): next_state(next_state) {};
    std::string get_description() override
    {
        return "Current state: IN_TRANSIT - Your item is on the way\n";
    }
    
    State *get_next_state() override {return next_state;};
};

class DeliveredState: public State {
    State *next_state = nullptr;
public:
    DeliveredState(State *next_state): next_state(next_state) {};
    
    std::string get_description() override
    {
        return "Current state: DELIVERED - Your item has arrived\n";
    }
    
    State *get_next_state() override {return next_state;};
};

class Purchase
{
    std::string product_name;
    State *current_state;
public:
    Purchase(const std::string &product_name, State *initial_state)
        :product_name(product_name), current_state(initial_state) {};
    
    std::string get_description()
    {
        return current_state->get_description();
    }
    
    void go_to_next_state()
    {
        if (current_state->get_next_state())
        {
            current_state = current_state->get_next_state();
        } else {
            std::cout << "No more states!" << std::endl;
        }
        
    }
    
};

int main(int argc, const char * argv[]) {
    
    DeliveredState *delivered = new DeliveredState(nullptr);
    InTransitState *in_transit = new InTransitState(delivered);
    PurchasedState *purchased = new PurchasedState(in_transit);
    
    Purchase *purchase = new Purchase("Shoes", purchased);
    std::cout << purchase->get_description() << "\n";
    
    purchase->go_to_next_state();
    std::cout << purchase->get_description() << "\n";
    
    purchase->go_to_next_state();
    std::cout << purchase->get_description() << "\n";
    
    delete delivered;
    delete in_transit;
    delete purchased;
    delete purchase;
    
    return 0;
}
