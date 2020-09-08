# Object Oriented Programming

## Table of Contents

* [Features](#features)
    * [Abstraction](#abstraction)
    * [Encapsulation](#encapsulation)
    * [Inheritance](#inheritance)
    * [Polymorphism](#polymorphism)

## Features
### Abstraction
We try to obtain abstract view, model or structure of real life problem, and reduce its unnecessary details. With definition of properties of problems, including the data which are affected and the operations which are identified, the model abstracted from problems can be a standard solution to this type of problems. It is an efficient way since there are nebulous real-life problems that have similar properties.

### Encapsulation
Encapsulation is the process of combining data and functions into a single unit called class. In Encapsulation, the data is not accessed directly; it is accessed through the functions present inside the class. In simpler words, attributes of the class are kept private and public getter and setter methods are provided to manipulate these attributes. Thus, encapsulation makes the concept of data hiding possible. (Data hiding: a language feature to restrict access to members of an object, reducing the negative effect due to dependencies. e.g. "protected", "private" feature in C++)

### Inheritance
The idea of inheritance is simple, a class is based on another class and uses data and implementation of the other class. And the purpose of inheritance is Code Reuse.

### Polymorphism
Polymorphism is the ability to present the same interface for differing underlying forms (data types). With polymorphism, each of these classes will have different underlying data. A point shape needs only two co-ordinates (assuming it's in a two-dimensional space of course). A circle needs a center and radius. A square or rectangle needs two co-ordinates for the top left and bottom right corners and (possibly) a rotation. An irregular polygon needs a series of lines.

For example, Automobile is the base case of Bus, Truck. However, the way to drive a Bus and a Truck may be slightly different so that the implementation of this drive() method is different. With polymorphism, you can instantiate objects with all the same declared type Automobile but different actual type (Bus, Truck etc,...) so that you can call the same method drive() with different implementations without checking the type of the object.