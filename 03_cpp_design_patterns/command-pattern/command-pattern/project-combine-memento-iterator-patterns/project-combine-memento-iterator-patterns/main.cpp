//
//  main.cpp
//  project-combine-memento-iterator-patterns
//
//  Created by Cristian on 18/04/22.
//

#include <iostream>
#include <vector>

//forward declaration
class Canvas;
class CanvasMemento;
class ReplayCanvas;

class CanvasIterator
{
public:
    ~CanvasIterator() {}
    virtual CanvasMemento *next() = 0;
    virtual bool is_finished() = 0;
};

class ForwarsdIterator: public CanvasIterator
{
    int current_position;
    std::vector<CanvasMemento*> &history;
public:
    ForwarsdIterator(std::vector<CanvasMemento*> &history)
    : current_position(0), history(history) {};
    
    CanvasMemento *next() override
    {
        CanvasMemento *current = history.at(current_position);
        current_position += 1;
        return current;
    }
    
    bool is_finished() override
    {
        return current_position >= history.size();
    }
};


class CanvasMemento
{
    // The Canvas class is a friend of this class,
    // it therefore can access private properties here
    friend class Canvas;
    friend class ReplayCanvas;
    const std::vector<std::string> shapes;
public:
    CanvasMemento(std::vector<std::string> shapes): shapes(shapes) {};
};


class History
{
public:
    virtual void add_state(CanvasMemento *new_state) = 0;
    virtual CanvasMemento *undo() = 0;
};

class CanvasHistory: public History
{
    std::vector<CanvasMemento *> old_states;
public:
    ~CanvasHistory() {
        for(auto state: old_states) { delete state;}
        old_states.clear();
    }
    
    void add_state(CanvasMemento *state) override
    {
        old_states.push_back(state);
    }
    
    CanvasMemento *undo() override
    {
        old_states.pop_back();
        CanvasMemento *previous_state = old_states.back();
        return previous_state;
    }
    
    ForwarsdIterator *get_forwardsiterator()
    {
        return new ForwarsdIterator(old_states);
    }
};

class NullHistory: public History
{
    CanvasMemento *null_state;
public:
    NullHistory() {
        null_state = new CanvasMemento({});
    }
    void add_state(CanvasMemento *new_state) override
    {
        null_state = new_state;
    };
    CanvasMemento *undo() override {return null_state;};
};

class Canvas
{
    std::vector<std::string> shapes;
    History *history;
public:
    Canvas(History *history): history(history) {};
    
    std::vector<std::string> get_shapes() {
        return shapes;
    }
    
    void add_shape(const std::string &new_shape)
    {
        shapes.push_back(new_shape);
        history->add_state(new CanvasMemento(shapes));
    }
    
    void undo()
    {
        CanvasMemento *previous_state = history->undo();
        shapes = previous_state->shapes;
        delete previous_state;
    }
    
    void clear_all()
    {
        shapes.clear();
        history->add_state(new CanvasMemento(shapes));
    }
};

class ReplayCanvas
{
    std::vector<std::string> shapes;
    ForwarsdIterator *history_iterator;
public:
    ReplayCanvas(CanvasHistory *history)
    {
        history_iterator = history->get_forwardsiterator();
    }
    
    void replay()
    {
        while(!history_iterator->is_finished())
        {
            CanvasMemento *next_state = history_iterator->next();
            shapes = next_state->shapes;
            std::cout << "The shapes are now: ";
            for(auto shape: shapes)
            {
                std::cout << shape << ", ";
            }
            
            std::cout << "\n";
        }
    }
};

int main(int argc, const char * argv[]) {
    NullHistory * history = new NullHistory;
    Canvas *canvas = new Canvas(history);
    
    canvas->add_shape("rhombus");
    canvas->add_shape("rhombus");
    canvas->add_shape("rhombus");
    canvas->add_shape("rhombus");
    /*std::cout << "Watching replay:\n";
    
    ReplayCanvas *replay_canvas = new ReplayCanvas(history);
    replay_canvas->replay();*/
    
    for(auto shape: canvas->get_shapes())
    {
        std::cout << shape << ", ";
    }
    
    std::cout << "\n";
    
    std::cout << "Trying to undo...\n";
    history->undo();
    history->undo();
    
    for(auto shape: canvas->get_shapes())
    {
        std::cout << shape << ", ";
    }
    
    std::cout << "\n";
    
    delete history;
    delete canvas;
    
    return 0;
}
