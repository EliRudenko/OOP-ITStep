import {Component, OnInit} from '@angular/core';

class Resume 
{
  constructor
  (
    public fullName: string,
    public email: string,
    public phone: string,
    public city: string,
    public experience: string,
    public skills: string[],
    public certifications: string[],
    public photoUrl: string,
    public links: { github: string; linkedin: string; twitter: string }
  ) { }
}

@Component
({
  selector: 'app-resume',
  standalone: true,
  imports: [],
  templateUrl: './resume.component.html',
  styleUrl: './resume.component.css'
})

export class ResumeComponent implements OnInit 
{
  resume: Resume[];

  constructor() { this.resume = []; }

  ngOnInit(): void 
  {
    const productData = [
      {
        fullName: 'Руденко Елена',
        email: 'rudenko.elin@gmail.com',
        phone: '+380 68 050 6080',
        city: 'Одесса',
        experience: 'Опыт работы в IT сфере более 3 лет. Работала на позициях Frontend Developer, Backend Developer. Участвовала в командных проектах. Руководила проектами',
        skills: ['HTML', 'CSS', 'JavaScript', 'Angular', 'C++'],
        certifications: ['1...', '2...'],
        photoUrl: '',
        links: {
          github: 'https://github.com/EliRudenko',
          linkedin: 'https://github.com/EliRudenko',
          twitter: 'https://github.com/EliRudenko'
        }
      }
    ];

    for (const data of productData) 
    {
      this.resume.push(
        new Resume(
          data.fullName, data.email, data.phone,
          data.city, data.experience, data.skills,
          data.certifications, data.photoUrl, data.links
        )
      );
    }

  }


}