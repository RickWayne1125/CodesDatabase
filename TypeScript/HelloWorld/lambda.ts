var shape = {
    name: "rectangle",
    popup: function() {

        console.log('This inside popup(): ' + this.name);

        // setInterval 每隔timeout毫秒时间便执行一次函数内容
        setInterval( () => {
            console.log('This inside setTimeout(): ' + this.name);
            console.log("I'm a " + this.name + "!");
        }, 3000);

        // setTimeout 间隔timeout时间后执行函数内容（仅执行一次）
        // setTimeout( () => {
        //     console.log('This inside setTimeout(): ' + this.name);
        //     console.log("I'm a " + this.name + "!");
        // }, 3000);

    }
};

shape.popup();