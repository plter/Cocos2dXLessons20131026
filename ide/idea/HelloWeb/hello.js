/**
 * Created with IntelliJ IDEA.
 * User: plter
 * Date: 13-11-17
 * Time: 下午3:17
 * To change this template use File | Settings | File Templates.
 */


function People(){

}

People.prototype.sayHi = function(){
    console.log("Hello People");
}


var p = new People();
p.sayHi();