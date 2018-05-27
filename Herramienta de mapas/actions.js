var map = [
  [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
  [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
  [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
  [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
  [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
  [0,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0],
  [3,5,5,4,0,3,4,0,0,0,0,0,0,3,4,0],
  [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]
];
var row = function(node){
    var gridElement = document.getElementsByClassName("grid");
    var div = document.createElement("div");
    div.setAttribute("id", 'fila-'+node);
    div.setAttribute("class", 'fila');
    gridElement[0].appendChild(div);
}
var column = function(node, tile){
    var rowElement = document.getElementById('fila-'+node);
    var newColumn = document.createElement("div");
    newColumn.setAttribute("class", 'tile-'+tile);
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
            console.log(tile);
            column(currentNode, tile);
        }
    }
};
