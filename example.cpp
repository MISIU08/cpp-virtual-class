
class string_view{
  virtual class construction_base{
    char* begin();
    char* end();
  };
  char*begin;
  char*end;
  string_view(construction_base& b){
    begin = b.begin();
    end = b.end();
  }
}
class my_string{/*content*/};

//allows to construct string_view from my_string 
virtual class string_view::construction_base : my_string{
    char* begin(){
      return this->begin();
    }
    char*end(){
      return this->end();
    }
};

int main(){
  my_string some_string;
  //uses string_view(construction_base& b) constructor
  string_view strv = some_string;
}
