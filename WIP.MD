# WIP

## TODO

 - [ ] Check si le buffer est impairt comment réagit le push de 3 élement d'un len de 1
> expexted behaviour
> ```
> vect_init() //size set @ `5`
> v_print();  // .....
> push_sep(t, 0)
> v_print();  // t....
> push_sep(t, 0)
> v_print();  // t.t..
> push_sep(t, 0)
> > auto_resize(vec.size * 2); // pas assez d'espace pour push le character et son séparateur.
> v_print();  // t.t.t.....
> ```

 - [ ] Comment calculer la taille arbitraire de l'index.
> Je pense choisir la moitier de la taille du buffer, comme ça dans le cas ou on push a chaque fois un élément avec un séparateur, exmple ci dessus, on ne pourras push que la moitier ou moins de la moitier en cas de size impairt.