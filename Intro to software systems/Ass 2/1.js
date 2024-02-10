let data;

(function () {
  const about = {
    typing: [
      ".Malla.Sailesh",
      ".a.Student",
      ".an.Enthusiast",
    ],
  };
  data = {about};
})();

const typeStart = () => {
    const typingElement = document.querySelector('.lab4');
    const sentences = data.about.typing;
  
    const letterWait = 100;
    const sentenceWait = 2000;
  
    const type = (sentence = -1, letter = -1, erasing) => {
      if (sentence === sentences.length) return type(0, letter, erasing);
  
      if (letter === -1) {
        var cur = document.querySelector('.cursor')
        cur.innerText = '';
        setTimeout(() => type(sentence + 1, 0, false), sentenceWait / 2);
      } else if (letter === sentences[sentence].length) {
        var cur = document.querySelector('.cursor')
        cur.innerText = '';
        setTimeout(() => type(sentence, letter - 1, true), sentenceWait);
      } else if (erasing) {
        var cur = document.querySelector('.cursor')
        cur.innerText = '|';
        typingElement.innerText = typingElement.innerText.slice(0, letter);
        setTimeout(() => type(sentence, letter - 1, true), letterWait);
      } else {
        var cur = document.querySelector('.cursor')
        cur.innerText = '_';
        if (sentences[sentence][letter] == '.') {
          var temp = ' ' + sentences[sentence][letter + 1];
          typingElement.innerText += temp;
          setTimeout(() => type(sentence, letter + 2, false), letterWait);
        }
        else {
          typingElement.innerText += sentences[sentence][letter];
          setTimeout(() => type(sentence, letter + 1, false), letterWait);
        }
      }
    };
    type();
  };

  typeStart();
  
  
  