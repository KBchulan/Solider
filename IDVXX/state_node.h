#ifndef _STATE_NODE_H_
#define _STATE_NODE_H_

class StateNode {
public:
    StateNode() = default;
    ~StateNode() = default;
    
    virtual void on_enter(){ }
    virtual void on_update(float delta){ }
    virtual void on_exit(){ }

};


#endif // !_STATE_NODE_H_
