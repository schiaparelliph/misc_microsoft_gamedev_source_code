namespace VisualEditor.PropertyPages
{
   partial class AnimPage
   {
      /// <summary> 
      /// Required designer variable.
      /// </summary>
      private System.ComponentModel.IContainer components = null;

      /// <summary> 
      /// Clean up any resources being used.
      /// </summary>
      /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
      protected override void Dispose(bool disposing)
      {
         if (disposing && (components != null))
         {
            components.Dispose();
         }
         base.Dispose(disposing);
      }

      #region Component Designer generated code

      /// <summary> 
      /// Required method for Designer support - do not modify 
      /// the contents of this method with the code editor.
      /// </summary>
      private void InitializeComponent()
      {
         this.groupBox1 = new System.Windows.Forms.GroupBox();
         this.exitActionBox = new System.Windows.Forms.GroupBox();
         this.tweenTimeNumericUpDown = new System.Windows.Forms.NumericUpDown();
         this.label2 = new System.Windows.Forms.Label();
         this.tweenToAnimation = new System.Windows.Forms.ComboBox();
         this.transitionRadioButton = new System.Windows.Forms.RadioButton();
         this.freezeRadioButton = new System.Windows.Forms.RadioButton();
         this.loopRadioButton = new System.Windows.Forms.RadioButton();
         this.comboBox1 = new System.Windows.Forms.ComboBox();
         this.label1 = new System.Windows.Forms.Label();
         this.groupBox1.SuspendLayout();
         this.exitActionBox.SuspendLayout();
         ((System.ComponentModel.ISupportInitialize)(this.tweenTimeNumericUpDown)).BeginInit();
         this.SuspendLayout();
         // 
         // groupBox1
         // 
         this.groupBox1.Anchor = System.Windows.Forms.AnchorStyles.None;
         this.groupBox1.Controls.Add(this.exitActionBox);
         this.groupBox1.Controls.Add(this.comboBox1);
         this.groupBox1.Controls.Add(this.label1);
         this.groupBox1.Location = new System.Drawing.Point(0, 0);
         this.groupBox1.Name = "groupBox1";
         this.groupBox1.Padding = new System.Windows.Forms.Padding(5, 16, 5, 3);
         this.groupBox1.Size = new System.Drawing.Size(350, 250);
         this.groupBox1.TabIndex = 2;
         this.groupBox1.TabStop = false;
         this.groupBox1.Text = "Anim Properties";
         // 
         // exitActionBox
         // 
         this.exitActionBox.Controls.Add(this.tweenTimeNumericUpDown);
         this.exitActionBox.Controls.Add(this.label2);
         this.exitActionBox.Controls.Add(this.tweenToAnimation);
         this.exitActionBox.Controls.Add(this.transitionRadioButton);
         this.exitActionBox.Controls.Add(this.freezeRadioButton);
         this.exitActionBox.Controls.Add(this.loopRadioButton);
         this.exitActionBox.Location = new System.Drawing.Point(11, 59);
         this.exitActionBox.Name = "exitActionBox";
         this.exitActionBox.Size = new System.Drawing.Size(331, 126);
         this.exitActionBox.TabIndex = 2;
         this.exitActionBox.TabStop = false;
         this.exitActionBox.Text = "Exit Action";
         // 
         // tweenTimeNumericUpDown
         // 
         this.tweenTimeNumericUpDown.Location = new System.Drawing.Point(85, 96);
         this.tweenTimeNumericUpDown.Maximum = new decimal(new int[] {
            1000,
            0,
            0,
            0});
         this.tweenTimeNumericUpDown.Name = "tweenTimeNumericUpDown";
         this.tweenTimeNumericUpDown.Size = new System.Drawing.Size(57, 20);
         this.tweenTimeNumericUpDown.TabIndex = 5;
         this.tweenTimeNumericUpDown.ValueChanged += new System.EventHandler(this.tweenTimeNumericUpDown_ValueChanged);
         // 
         // label2
         // 
         this.label2.AutoSize = true;
         this.label2.Location = new System.Drawing.Point(4, 98);
         this.label2.Name = "label2";
         this.label2.Size = new System.Drawing.Size(66, 13);
         this.label2.TabIndex = 4;
         this.label2.Text = "Tween Time";
         // 
         // tweenToAnimation
         // 
         this.tweenToAnimation.Enabled = false;
         this.tweenToAnimation.FormattingEnabled = true;
         this.tweenToAnimation.Location = new System.Drawing.Point(85, 68);
         this.tweenToAnimation.Name = "tweenToAnimation";
         this.tweenToAnimation.Size = new System.Drawing.Size(240, 21);
         this.tweenToAnimation.TabIndex = 3;
         this.tweenToAnimation.TextChanged += new System.EventHandler(this.tweenToAnimation_TextChanged);
         // 
         // transitionRadioButton
         // 
         this.transitionRadioButton.AutoSize = true;
         this.transitionRadioButton.Location = new System.Drawing.Point(7, 68);
         this.transitionRadioButton.Name = "transitionRadioButton";
         this.transitionRadioButton.Size = new System.Drawing.Size(71, 17);
         this.transitionRadioButton.TabIndex = 2;
         this.transitionRadioButton.Text = "Transition";
         this.transitionRadioButton.UseVisualStyleBackColor = true;
         this.transitionRadioButton.CheckedChanged += new System.EventHandler(this.transitionRadioButton_CheckedChanged);
         // 
         // freezeRadioButton
         // 
         this.freezeRadioButton.AutoSize = true;
         this.freezeRadioButton.Location = new System.Drawing.Point(7, 44);
         this.freezeRadioButton.Name = "freezeRadioButton";
         this.freezeRadioButton.Size = new System.Drawing.Size(57, 17);
         this.freezeRadioButton.TabIndex = 1;
         this.freezeRadioButton.Text = "Freeze";
         this.freezeRadioButton.UseVisualStyleBackColor = true;
         this.freezeRadioButton.CheckedChanged += new System.EventHandler(this.freezeRadioButton_CheckedChanged);
         // 
         // loopRadioButton
         // 
         this.loopRadioButton.AutoSize = true;
         this.loopRadioButton.Checked = true;
         this.loopRadioButton.Location = new System.Drawing.Point(7, 20);
         this.loopRadioButton.Name = "loopRadioButton";
         this.loopRadioButton.Size = new System.Drawing.Size(49, 17);
         this.loopRadioButton.TabIndex = 0;
         this.loopRadioButton.TabStop = true;
         this.loopRadioButton.Text = "Loop";
         this.loopRadioButton.UseVisualStyleBackColor = true;
         this.loopRadioButton.CheckedChanged += new System.EventHandler(this.loopRadioButton_CheckedChanged);
         // 
         // comboBox1
         // 
         this.comboBox1.FormattingEnabled = true;
         this.comboBox1.Location = new System.Drawing.Point(102, 32);
         this.comboBox1.Name = "comboBox1";
         this.comboBox1.Size = new System.Drawing.Size(240, 21);
         this.comboBox1.TabIndex = 1;
         this.comboBox1.TextChanged += new System.EventHandler(this.comboBox1_TextChanged);
         // 
         // label1
         // 
         this.label1.AutoSize = true;
         this.label1.Location = new System.Drawing.Point(8, 35);
         this.label1.Name = "label1";
         this.label1.Size = new System.Drawing.Size(61, 13);
         this.label1.TabIndex = 0;
         this.label1.Text = "Anim Name";
         // 
         // AnimPage
         // 
         this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
         this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
         this.Controls.Add(this.groupBox1);
         this.Name = "AnimPage";
         this.Size = new System.Drawing.Size(350, 250);
         this.groupBox1.ResumeLayout(false);
         this.groupBox1.PerformLayout();
         this.exitActionBox.ResumeLayout(false);
         this.exitActionBox.PerformLayout();
         ((System.ComponentModel.ISupportInitialize)(this.tweenTimeNumericUpDown)).EndInit();
         this.ResumeLayout(false);

      }

      #endregion

      private System.Windows.Forms.GroupBox groupBox1;
      private System.Windows.Forms.ComboBox comboBox1;
      private System.Windows.Forms.Label label1;
      private System.Windows.Forms.GroupBox exitActionBox;
      private System.Windows.Forms.RadioButton freezeRadioButton;
      private System.Windows.Forms.RadioButton loopRadioButton;
      private System.Windows.Forms.ComboBox tweenToAnimation;
      private System.Windows.Forms.RadioButton transitionRadioButton;
      private System.Windows.Forms.NumericUpDown tweenTimeNumericUpDown;
      private System.Windows.Forms.Label label2;
   }
}
