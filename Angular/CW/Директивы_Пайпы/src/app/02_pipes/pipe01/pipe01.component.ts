import { Component, OnInit } from '@angular/core';
import { CommonModule } from '@angular/common';

@Component({
  selector: 'app-pipe01',
  standalone:true,
  imports:[CommonModule],
  templateUrl: './pipe01.component.html'
})
export class Pipe01Component implements OnInit {

  textOne = 'Пример текста';
  textTwo = 'ВЕРХНИЙ РЕГИСТР';

  varNumber = Math.PI;

  
  constructor() { }

  ngOnInit(): void {
  }

}
