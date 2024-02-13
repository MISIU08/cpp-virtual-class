# virtual class, an idea for a c++ language extension

Some programming languages have an interesting way to share common behaviour between multiple classes, in C# they are called interfaces and in rust they are called traits
They define a common "interface" to use witch can be later implemented for multiple classes

I thought it would be cool to have it in C++
So I came up with this:
```
virtual class window{
    void show();
    void hide();
    void resize(int x,int y);
}

class main_window{
    void show_window();
    void hide_window();
    void resize_window();
    void add_element();
}


```
