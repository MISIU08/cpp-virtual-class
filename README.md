## virtual class, an idea for a c++ language extension

Some programming languages have an interesting way to share common behaviour between multiple classes, in C# they are called interfaces and in rust they are called traits.
<br>
They define a common "interface" to use witch can be later implemented for multiple classes

I thought it would be cool to have it in C++

Suppose we have a class player and a class enemy:
```

class player{
    void set_pos(int x, int y);
    void move(int x_steps,int y_steps,int seconds);
    void change_state(state& s);

}

class enemy{
    void set_pos(int x, int y);
    void move(int x_steps,int y_steps,int seconds);
    void change_agreesion_level(agression_level& agg_lvl);
}

```


