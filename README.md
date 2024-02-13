## virtual class, an idea for a c++ language extension

Some programming languages have an interesting way to share common behaviour between multiple classes, in C# they are called interfaces and in rust they are called traits.
<br>
They define a common "interface" to use witch can be later implemented for multiple classes

I thought it would be cool to have it in C++
So I came up with this:
```
virtual class sprite{
    void set_pos(int x, int y);
    void move(int x_steps,int y_steps,int seconds);
}

class player{
    void set_pos(int x, int y);
    void move(int x_steps,int y_steps,int seconds);
    void change_state(state& s);

}
virtual class sprite: player{
    using set_pos = player::set_pos;
    using move = player::move;
}

class enemy{
    void set_pos(int x, int y);
    void move(int x_steps,int y_steps,int seconds);
    void change_agreesion_level(agression_level& agg_lvl);
}

virtual class sprite: enemy{
    using set_pos = enemy::set_pos;
    using move = enemy::move;
}

//the function doesn't care what kind of sprite it is getting
//it uses the virtual class sprite to interface with all kinds of sprite
void make_animation_with(sprite& s){
    s.move(15,5,1);
    s.move(5,15,1);
    s.move(-15,-5,1);
    s.move(-5,-15,1);
}

int main(){
    player p;
    enemy n;

    //calling: void make_animation_with(sprite& s)
    make_animation_with(p);

    //calling: void make_animation_with(sprite& s)
    make_animation_with(e);

}

```
