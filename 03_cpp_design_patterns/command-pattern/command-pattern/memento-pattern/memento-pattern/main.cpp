//
//  main.cpp
//  memento-pattern
//
//  Created by Cristian on 18/04/22.
//

#include <iostream>
#include <vector>

//forward declaration
class Canvas;

class CanvasMemento
{
    // The Canvas class is a friend of this class,
    // it therefore can access private properties here
    friend class Canvas;
    const std::vector<std::string> shapes;
public:
    CanvasMemento(std::vector<std::string> shapes): shapes(shapes) {};
};

class Canvas
{
    std::vector<std::string> shapes;
    std::vector<CanvasMemento*> old_states;
public:
    ~Canvas()
    {
        for(auto state: old_states)
        {
            delete state;
        }
        old_states.clear();
    }
    
    std::vector<std::string> get_shapes() {
        return shapes;
    }
    
    void add_shape(const std::string &new_shape)
    {
        old_states.push_back(new CanvasMemento(shapes));
        shapes.push_back(new_shape);
    }
    
    void undo()
    {
        CanvasMemento *previous_state = old_states.back();
        old_states.pop_back();
        shapes = previous_state->shapes;
        delete previous_state;
    }
    
    void clear_all()
    {
        shapes.clear();
    }
};

int main(int argc, const char * argv[]) {
    Canvas *canvas = new Canvas;
    
    canvas->add_shape("rhombus");
    canvas->add_shape("triangle");
    canvas->add_shape("square");
    canvas->add_shape("circle");
    
    for(auto shape: canvas->get_shapes())
    {
        std::cout << shape << ", ";
    }
    
    std::cout << "\n";
    
    canvas->undo();
    
    for(auto shape: canvas->get_shapes())
    {
        std::cout << shape << ", ";
    }
    
    std::cout << "\n";
    
    canvas->add_shape("rhombus");
    canvas->add_shape("triangle");
    canvas->add_shape("square");
    canvas->add_shape("circle");
    canvas->undo();
    
    for(auto shape: canvas->get_shapes())
    {
        std::cout << shape << ", ";
    }
    
    std::cout << "\n";
    
    delete canvas;
    
    return 0;
}
