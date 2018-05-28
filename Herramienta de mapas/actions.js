var map = [
  [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
  [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
  [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
  [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
  [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
  [0,3,4,0,0,0,0,0,7,0,0,0,0,0,0,0],
  [3,5,5,4,0,3,4,0,6,0,0,0,0,3,4,0],
  [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
];
var row = function(node){
    var gridElement = document.getElementsByClassName("grid");
    var div = document.createElement("div");
    div.setAttribute("id", 'fila-'+node);
    div.setAttribute("class", 'fila');
    gridElement[0].appendChild(div);
}
var column = function(node, tile, index){
    var rowElement = document.getElementById('fila-'+node);
    var newColumn = document.createElement("div");
    newColumn.setAttribute("Id", index);
    newColumn.setAttribute("class", 'tile-'+tile);
    newColumn.setAttribute("onClick", 'readTile(this.getAttribute("id"))');
    rowElement.appendChild(newColumn);
}
var curentNode;
var start = function(){
    for (var i = 0; i < map.length; i++) {
        var node = map[i];
        currentNode = i;
        row(i);
        //console.log(node);
        for (var j = 0; j < node.length; j++) {
            var tile= node[j];
            var index = currentNode + '-' +j;
            //console.log(tile);
            column(currentNode, tile, index);
        }
    };
    var html='';
        for (var i=0; i<= map.length -1; i++) {
            html+='<div>'+'{'+map[i]+'},'+'</div>';
        }
        document.getElementById('theOutPut').innerHTML+= html;
        document.getElementById('length').innerHTML= 'Map size: '+ map.length +'x'+ map[0].length;
};

var addColumn = function() {
    var gridElement = document.getElementsByClassName("grid");
    for (var i = 0; i < map.length; i++) {
        var node = map[i];
        node.push(0);
        curentNode = 0;
    };
    document.getElementById('theOutPut').innerHTML = "";
    gridElement[0].innerHTML = "";
    start();
};

var removeColumn = function() {
    var gridElement = document.getElementsByClassName("grid");
    for (var i = 0; i < map.length; i++) {
        var node = map[i];
        node.pop();
        curentNode = 0;
    };
    document.getElementById('theOutPut').innerHTML = "";
    gridElement[0].innerHTML = "";
    start();
}
var readTile = function(tile) {
    document.getElementById('selected').innerHTML = 'Selected Tile: '+ tile;
    console.log();
}
