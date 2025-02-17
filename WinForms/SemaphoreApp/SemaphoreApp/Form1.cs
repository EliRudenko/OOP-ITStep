using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace SemaphoreApp
{
    public partial class Form1 : Form
    {
        private Semaphore semaphore;
        private int freeSlots;
        private int threadCount = 1;
        private List<Thread> createdThreads = new List<Thread>();
        private List<Thread> waitingThreads = new List<Thread>();
        private List<Thread> workingThreads = new List<Thread>();
        private Dictionary<Thread, int> threadCounters = new Dictionary<Thread, int>();

        private Button btnCreateThread;
        private ListBox lstCreatedThreads;
        private ListBox lstWaitingThreads;
        private ListBox lstWorkingThreads;
        private Label lblFreeSlots;
        private NumericUpDown numFreeSlots;

        public Form1()
        {
            InitializeComponent();
            InitializeUI();

            // Инициализация семафора с 3 свободными местами
            freeSlots = 3;
            semaphore = new Semaphore(freeSlots, freeSlots);
            UpdateSlotCount();
        }

        private void InitializeUI()
        {
            // Кнопка для создания потока
            btnCreateThread = new Button
            {
                Text = "Создать поток",
                Location = new System.Drawing.Point(20, 20),
                Size = new System.Drawing.Size(150, 30)
            };
            btnCreateThread.Click += btnCreateThread_Click;

            // Список для отображения созданных потоков
            lstCreatedThreads = new ListBox
            {
                Location = new System.Drawing.Point(20, 60),
                Size = new System.Drawing.Size(150, 200)
            };
            lstCreatedThreads.DoubleClick += lstCreatedThreads_DoubleClick;

            // Список для отображения ожидающих потоков
            lstWaitingThreads = new ListBox
            {
                Location = new System.Drawing.Point(180, 60),
                Size = new System.Drawing.Size(150, 200)
            };
            lstWaitingThreads.DoubleClick += lstWaitingThreads_DoubleClick;

            // Список для отображения рабочих потоков
            lstWorkingThreads = new ListBox
            {
                Location = new System.Drawing.Point(340, 60),
                Size = new System.Drawing.Size(150, 200)
            };
            lstWorkingThreads.DoubleClick += lstWorkingThreads_DoubleClick;

            // Метка для отображения свободных мест
            lblFreeSlots = new Label
            {
                Text = "Свободные места: 3",
                Location = new System.Drawing.Point(20, 280),
                Size = new System.Drawing.Size(150, 30)
            };

            // NumericUpDown для изменения количества слотов
            numFreeSlots = new NumericUpDown
            {
                Location = new System.Drawing.Point(180, 280),
                Size = new System.Drawing.Size(120, 30),
                Minimum = 1,
                Maximum = 10,
                Value = 3
            };
            numFreeSlots.ValueChanged += numFreeSlots_ValueChanged;

            // Добавляем элементы управления на форму
            this.Controls.Add(btnCreateThread);
            this.Controls.Add(lstCreatedThreads);
            this.Controls.Add(lstWaitingThreads);
            this.Controls.Add(lstWorkingThreads);
            this.Controls.Add(lblFreeSlots);
            this.Controls.Add(numFreeSlots);
        }

        private void UpdateSlotCount()
        {
            lblFreeSlots.Text = "Свободные места: " + freeSlots.ToString();
        }

        private void btnCreateThread_Click(object sender, EventArgs e)
        {
            var thread = new Thread(ThreadWork);
            thread.Name = $"Поток {threadCount++}";  // Устанавливаем имя потока
            createdThreads.Add(thread);
            lstCreatedThreads.Items.Add(thread.Name + " (создан)");  // Добавляем в список созданных с пометкой
        }

        private void lstCreatedThreads_DoubleClick(object sender, EventArgs e)
        {
            if (lstCreatedThreads.SelectedItem != null)
            {
                int selectedIndex = lstCreatedThreads.SelectedIndex;
                var selectedThread = createdThreads[selectedIndex];
                createdThreads.RemoveAt(selectedIndex);
                lstCreatedThreads.Items.RemoveAt(selectedIndex);

                waitingThreads.Add(selectedThread);
                lstWaitingThreads.Items.Add(selectedThread.Name + " (ожидается)");  // Помечаем как ожидающий
            }
        }

        private void lstWaitingThreads_DoubleClick(object sender, EventArgs e)
        {
            if (lstWaitingThreads.SelectedItem != null)
            {
                int selectedIndex = lstWaitingThreads.SelectedIndex;
                var selectedThread = waitingThreads[selectedIndex];
                waitingThreads.RemoveAt(selectedIndex);
                lstWaitingThreads.Items.RemoveAt(selectedIndex);

                // Попытка занять место в семафоре
                semaphore.WaitOne();

                workingThreads.Add(selectedThread);
                lstWorkingThreads.Items.Add(selectedThread.Name + " (работает)");  // Помечаем как работающий

                // Запуск работы потока
                selectedThread.Start();
            }
        }

        private void lstWorkingThreads_DoubleClick(object sender, EventArgs e)
        {
            if (lstWorkingThreads.SelectedItem != null)
            {
                int selectedIndex = lstWorkingThreads.SelectedIndex;
                var selectedThread = workingThreads[selectedIndex];
                workingThreads.RemoveAt(selectedIndex);
                lstWorkingThreads.Items.RemoveAt(selectedIndex);

                // Останавливаем поток
                selectedThread.Abort();

                // Освобождаем место в семафоре
                semaphore.Release();
                UpdateSlotCount();
            }
        }

        private void ThreadWork()
        {
            var thread = Thread.CurrentThread;
            int counter = 0;
            threadCounters[thread] = counter;

            while (true)
            {
                Thread.Sleep(1000);  // Работа потока, каждую секунду увеличиваем счетчик
                counter++;
                threadCounters[thread] = counter;

                // Отображаем состояние потока в UI
                Invoke(new Action(() =>
                {
                    int index = lstWorkingThreads.Items.IndexOf(thread.Name + " (работает)");
                    if (index != -1)
                    {
                        lstWorkingThreads.Items[index] = $"{thread.Name} - {counter} (работает)";
                    }
                }));
            }
        }

        private void numFreeSlots_ValueChanged(object sender, EventArgs e)
        {
            freeSlots = (int)numFreeSlots.Value;
            semaphore = new Semaphore(freeSlots, freeSlots);

            // Обновляем количество слотов
            UpdateSlotCount();

            // Если уменьшилось количество слотов, удаляем старые потоки
            if (freeSlots < workingThreads.Count)
            {
                int excessCount = workingThreads.Count - freeSlots;
                for (int i = 0; i < excessCount; i++)
                {
                    var threadToRemove = workingThreads.Last();
                    workingThreads.RemoveAt(workingThreads.Count - 1);
                    lstWorkingThreads.Items.RemoveAt(lstWorkingThreads.Items.Count - 1);

                    threadToRemove.Abort();
                    semaphore.Release();
                }
            }

            // Если увеличилось количество слотов, добавляем новые ожидающие потоки
            for (int i = 0; i < freeSlots - workingThreads.Count; i++)
            {
                if (waitingThreads.Count > 0)
                {
                    var waitingThread = waitingThreads[0];
                    waitingThreads.RemoveAt(0);
                    lstWaitingThreads.Items.RemoveAt(0);

                    semaphore.WaitOne();  // Блокируем семафор

                    workingThreads.Add(waitingThread);
                    lstWorkingThreads.Items.Add(waitingThread.Name + " (работает)");
                    waitingThread.Start();
                }
            }
        }
    }
}
