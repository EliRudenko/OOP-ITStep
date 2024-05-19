import { Component, OnInit } from '@angular/core';
import { CommonModule } from '@angular/common';
@Component({
  selector: 'app-pipe02',
  standalone:true,
  imports:[CommonModule],
  templateUrl: './pipe02.component.html'
})
export class Pipe02Component implements OnInit {


  date: Date = new Date(1992, 8, 16);


  constructor() { }
  ngOnInit(): void {
  }

}
