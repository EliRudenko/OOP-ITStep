import { Component, OnInit } from '@angular/core';
import { CommonModule } from '@angular/common';

@Component({
  selector: 'app-pipe03',
  standalone:true,
  imports:[CommonModule],
  templateUrl: './pipe03.component.html'
})
export class Pipe03Component implements OnInit {

  constructor() { }
  float: number = 0.55;

  obj = {
    a: 1,
    b: 'hihi',
    c: {
      f: 'hello',
      g: 55
    }
  }
  ngOnInit(): void {
  }

}
