let randomNumber = parseInt(Math.random()*100 + 1)
const submit = document.querySelector('#subt')
const userinput= document.querySelector('#guessField')
const guessSlot= document.querySelector('.guesses')
const remaining = document.querySelector('.lastresult')
const  lowOrhi = document.querySelector('.lowOrHi')
const startover = document.querySelector('.resultParas')


const p = document.createElement('p')

let preGuess = []
let numGuess = 1

let playGame = true;

if(playGame){
    submit.addEventListener('click', function(e){
        e.preventDefault()
        const guess = parseInt(userinput.value)
        validateGuess(guess)
    })
}


function validateGuess(guess){
   if(isNaN(guess)){
    alert('Please enter a valid number')
   } 
   else if(guess<1){
    alert('Please enter a number more then 1')
   }
   else if(guess>100){
    alert('Please enter a number less then 100')
   }
   else{
    preGuess.push(guess)
    if(numGuess===10){
        displayGuess(guess)
        displayMessage(`Game Over.Random number was ${randomNumber}`)
        endGame()
    }
    else {
        displayGuess(guess)
        checkGuess(guess)
    }
   }
}

function checkGuess(guess){
 if(guess===randomNumber){
    displayMessage(`You guessed right number`)
    endGame()
 }
 else if(guess<randomNumber){
    displayMessage(`Number is too low`)
 }
 else if(guess>randomNumber){
    displayMessage(`Number is too high`)
 }
}

function displayGuess(guess){
 userinput.value = ' '
 guessSlot.innerHTML += `${guess}, `
 numGuess++;
 remaining.innerHTML = `${11-numGuess}`
}

function displayMessage(message){
 lowOrhi.innerHTML = `<h2>${message}</h2>`
}

function endGame(){
 userinput.value = ''
 userinput.setAttribute('disabled','')
 p.classList.add('button')
 p.innerHTML = `<h2 id="newGame"> Start new Game</h2>`
 startover.appendChild(p)
 playGame = false
 newGame()
}

function newGame(){
   const newgameButten = document.querySelector('#newGame')
   newgameButten.addEventListener('click',function(e){
    randomNumber = parseInt(Math.random()*100 + 1)
    preGuess = []
    numGuess = 1
    guessSlot.innerHTML = ''
    remaining.innerHTML = `${11-numGuess}`
    userinput.removeAttribute('disabled')
    startover.removeChild(p);

    playGame = true
   })
}