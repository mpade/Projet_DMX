function Rechargement(nomprog) {
    var newRechargement = {
        rechargement: document.getElementById('nameprog').value
    };
    var tab = new FormData();
    tab.append("json", JSON.stringify(newRechargement));
    fetch("../index2.php", {
        method: "GET",
        body: tab
    })
        .then(function (res) {
            return res.json();
        })
        .then(function (tab) {
            console.log(tab)
        


        });
}