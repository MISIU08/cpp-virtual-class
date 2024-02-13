# Virtual class: An idea for a c++ language extension

Some programming languages have an interesting way to share common behaviour between multiple classes, in C# they are called interfaces and in rust they are called traits.
<br>
They define a common "interface" to use witch can be later implemented for multiple classes

I thought it would be cool to have it in C++

## What is their purpose?

Suppose we have a class player and a class enemy:
```
class player{
    void set_player_pos(int x, int y);
    void move_player(int x_steps,int y_steps,int seconds);
    void change_state(state& s);

}

class enemy{
    void set_enemy_pos(int x, int y);
    void move_enemy(int x_steps,int y_steps,int seconds);
    void change_agreesion_level(agression_level& agg_lvl);
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

here come virtual classes.
<br>
virtual classes would allow to make a common interface to use for multiple classes 

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

Now we can make an animate function accepting all entyties witch define an "interface" for 
