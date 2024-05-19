import { Component, OnInit } from '@angular/core';
import { CommonModule } from '@angular/common';
@Component({
  selector: 'app-directive02ng-style',
  standalone:true,
  imports:[CommonModule],
  templateUrl: './directive02ng-style.component.html',
  styleUrls: ['./directive02ng-style.component.css']
})
export class Directive02ngStyleComponent implements OnInit {

  toggle = true;

  constructor() { }
  ngOnInit(): void {
  }

}
