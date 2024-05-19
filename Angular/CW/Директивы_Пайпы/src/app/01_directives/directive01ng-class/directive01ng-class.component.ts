import { Component, OnInit } from '@angular/core';
import { CommonModule } from '@angular/common';
@Component({
  selector: 'app-directive01ng-class',
  standalone:true,
  imports:[CommonModule],
  templateUrl: './directive01ng-class.component.html',
  styleUrls: ['./directive01ng-class.component.css']
})
export class Directive01NgClassComponent implements OnInit {

  flag = true;


  constructor() { }
  ngOnInit(): void {
  }

}
