function Programme_Suppresion(prog) {

    var newSupresion = {

    };
    var tab = new FormData();
    tab.append("json", JSON.stringify(newSupresion));
    fetch("API/suppresion.php", {
        method: "POST",
        body: tab
    })
        .then(function (res) {
            return res.json();
        })
        .then(function (tab) {
            console.log(tab)


        });

}

function Programme_creation(nomprog) {
    var newCreation = {
        name_prog : document.getElementById('nameprog').value
    };
    var tab = new FormData();
    tab.append("json", JSON.stringify(newCreation));
    fetch("API/creation.php", {
        method: "POST",
        body: tab
    })
        .then(function (res) {
            return res.json();
        })
        .then(function (tab) {
            console.log(tab)
        


        });
}

// function Programme_Modification(prog){
//     var newModification = {
//         name_prog : document.getElementById('nameprog').value
//     };
//     var tab = new FormData();
//     tab.append("json", JSON.stringify(newModification));
//     fetch("API/modification.php", {
//         method: "POST",
//         body: tab
//     })
//     .then(function(res) {
//         return res.json();
//     })
//     .then(function (tab) {
//         console.log(tab)
//     });

// }

