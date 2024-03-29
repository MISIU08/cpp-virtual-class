# Virtual class: An idea for a C++ language extension

Some programming languages have an interesting way to share common behaviour between multiple classes, in C# they are called interfaces and in rust they are called traits.
<br>
They allow you to create a common "interface" for using multiple classes.

I thought it would be cool to have it in C++

## What is their purpose?

Suppose we have a class player and a class enemy:
```
class player{
public:
    void set_player_pos(int x, int y);
    void move_player(int x_steps,int y_steps,int seconds);
    void change_state(state& s);
    int posx;
    int posy;

}

class enemy{
public:
    void set_enemy_pos(int x, int y);
    void move_enemy(int x_steps,int y_steps,int seconds);
    void change_agreesion_level(agression_level& agg_lvl);
    int posx;
    int posy;
}
```

Now immagine that we want to make an Animation for both player and enemy.
<br>
We may think of making a different version of the animate function for both of them: 

```
namespace animations{
void animation1(player& p){
    p.move_player(15,5,1);
    p.move_player(5,15,1);
    p.move_player(-15,-5,1);
    p.move_player(-5,-15,1);
}
void animation1(enemy& e){
    e.move_enemy(15,5,1);
    e.move_enemy(5,15,1);
    e.move_enemy(-15,-5,1);
    e.move_enemy(-5,-15,1);
}
}
```

This approach is really unefective, What if we want to add a second animation? What if we want to add a third entity?

Here virtual classes could come in handy.
<br>
Why? Because they could allow to make a common "interface" to use, for both entity and player.

```
virtual class entity{
    void set_pos(int x, int y);
    void move(int x_steps,int y_steps,int seconds);
}

virtual class entity: player{
    using set_pos = player::set_player_pos;
    using move = player::move;
}

virtual class entity: enemy{
    using set_pos = enemy::set_enemy_pos;
    using move = enemy::move_enemy
}
```

Now we can make an animate function accepting all entities witch define an "interface" for the virtual class entity:

```
namespace animations{
void animation1(sprite& s){
    s.move(15,5,1);
    s.move(5,15,1);
    s.move(-15,-5,1);
    s.move(-5,-15,1);
}
}

```
Now we can use this function for both player and enemy
```
int main(){
    player p;
    enemy en;

    //calls void animation1(sprite& s)
    animations::animation1(p);
    //this also calls void animation1(sprite& s)
    animations::animation1(en);
}
```

What if we want to make a new animation? We can just make a new function accepting the virtual class entity:
```
namespace animations{
void animation1(sprite& s){//code}

void animation2(sprite& s){
    s.move(20,-20,1);
    s.move(-20,20,1);
}
}

```
And what about adding a new entity?
```
class square{
    int posx;
    int posy;
}

virtual class entity:square{
    void set_pos(int x,int y){
        this->posx=x;
        this->posy =y;
    }
    void move(int x_steps, int y_steps, int seconds){
        //code
    }
}

```


## Advantage over classes with pure virtual function

Many of you could probably point out that we can already do something similar: use classes with pure virtual functions.
<br>
But It think virtual classes have some advantages.

### Advantage nb 1
Classes interfacable with the virtual class don't have to be directly related with it.
<br>
