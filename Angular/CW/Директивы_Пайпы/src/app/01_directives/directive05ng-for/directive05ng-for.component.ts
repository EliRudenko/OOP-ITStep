import { Component, OnInit } from '@angular/core';
import { CommonModule } from '@angular/common';
@Component({
  selector: 'app-directive05ng-for',
  standalone:true,
  imports:[CommonModule],
  templateUrl: './directive05ng-for.component.html',
  styleUrls: ['directive05ng-for.component.css']
})
export class Directive05ngForComponent implements OnInit {


  arrStr = [
    'Первая строка',
    'Текст два',
    'Третье значение'
  ]

  addStr(){
    this.arrStr.push('Новый li элемент ' + (this.arrStr.length + 1));
  }

  arrObjs = [
    {prop: 'пункт списка 1'},
    {prop: 'пункт списка 2'},
    {prop: 'пункт списка 3'},
    {prop: 'пункт списка 4'},
    {prop: 'пункт списка 5'},
    {prop: 'пункт списка 6'},
    {prop: 'пункт списка 7'},
    {prop: 'пункт списка 8'},
  ]

  constructor() { }

  ngOnInit(): void {
  }
}
