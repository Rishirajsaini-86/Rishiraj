let btne4 = document.querySelector(".button_layout");
let body = document.querySelector("body");
let currmode = "dark";

btne4.addEventListener("click", ()=>{
    if (currmode === "dark"){
        currmode = "light"
        body.classList.add("dark")
    }else{
        currmode = "light";
        body.classList.add("dark");
    }
    console.log(currmode);
});