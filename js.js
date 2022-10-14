
const allpanel = document.querySelectorAll('.panel');


function movieP() {
    console.log('cmmcw');

    this.classList.toggle('open');
};

function swipeText(e) {

    if (e.propertyName.includes("flex")) {
        this.classList.toggle('open-active')
    }

};



allpanel.forEach(panel => panel.addEventListener("click", movieP));
allpanel.forEach(panel => panel.addEventListener("transitionend", swipeText));