class Shape {

    area: number;
    color: string;
    name: string;
    width: number;
    height: number;

    constructor(name: string, width: number, height: number) {
        this.area = width * height;
        this.color = "pink";
    };

    shoutout() {
        return "I'm " + this.color + " " + this.name + " with an area of " + this.area + " cm squared.";
    }
}

var square = new Shape("square", 30, 30);

console.log(square.shoutout());
console.log('Area of Shape: ' + square.area);
console.log('Name of Shape: ' + square.name);
console.log('Color of Shape: ' + square.color);
console.log('Width of Shape: ' + square.width);
console.log('Height of Shape: ' + square.height);

class Shape3D extends Shape {

    volume: number;

    constructor ( public name: string, width: number, height: number, length: number ) {
        super( name, width, height );
        this.volume = length * this.area;
    };

    shoutout() {
        return "I'm " + this.name +  " with a volume of " + this.volume + " cm cube.";
    }

    superShout() {
        return super.shoutout();
    }
}

var cube = new Shape3D("cube", 30, 30, 30);
console.log( cube.shoutout() );
console.log( cube.superShout() );